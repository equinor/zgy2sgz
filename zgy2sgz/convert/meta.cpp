/** Copyright 2020 Schlumberger
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *     http://www.apache.org/licenses/LICENSE-2.0
  * 
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
*/

// Since this is example code that should be buildable outside the
// Salmon baseline, it is possible (but perhaps not desirable)
// to not use the full include path but instead rely on the
// compiler having -I directives for all public header directories,
// and to pick up local headers from the current directory.
// So, we can include Api files as either
//   #include <Salmon/Zgy/Api/SOMETHING.h>
//   #include <SOMETHING.h>
// and local includes can be either
//   #include <Salmon/Zgy/Api/Example/SOMETHING.h>
//   #include "SOMETHING.h"
// Using the Salmon convention does have its benefits,
// as it allows more verification in the deploy scripts.

#include <Salmon/Zgy/Api/MetaDataKey.h>
#include <Salmon/Zgy/Api/MetaDataValue.h>

#include <Salmon/Zgy/Api/Example/utils.h>
#include <Salmon/Zgy/Api/Example/meta.h>

#include <string.h>

#define TRANSLATE_FIELDS \
  TRANSLATE(Size0,          size[0]) \
  TRANSLATE(Size1,          size[1]) \
  TRANSLATE(Size2,          size[2]) \
  TRANSLATE(DataType,       datatype) \
  TRANSLATE(DataMin,        datamin) \
  TRANSLATE(DataMax,        datamax) \
  TRANSLATE(ZUnitDim,       zunitdim) \
  TRANSLATE(ZUnitName,      zunitname) \
  TRANSLATE(ZUnitFactor,    zunitfactor) \
  TRANSLATE(ZStart,         z0) \
  TRANSLATE(ZInc,           dz) \
  TRANSLATE(InlineStart,    hannot0[0]) \
  TRANSLATE(InlineInc,      dhannot[0]) \
  TRANSLATE(CrosslineStart, hannot0[1]) \
  TRANSLATE(CrosslineInc,   dhannot[1]) \
  TRANSLATE(HUnitDim,       hunitdim) \
  TRANSLATE(HUnitName,      hunitname) \
  TRANSLATE(HUnitFactor,    hunitfactor) \
  TRANSLATE(HCorner00X,     hcornerxy[Corner00][0]) \
  TRANSLATE(HCorner00Y,     hcornerxy[Corner00][1]) \
  TRANSLATE(HCornerM0X,     hcornerxy[CornerM0][0]) \
  TRANSLATE(HCornerM0Y,     hcornerxy[CornerM0][1]) \
  TRANSLATE(HCorner0NX,     hcornerxy[Corner0N][0]) \
  TRANSLATE(HCorner0NY,     hcornerxy[Corner0N][1]) \
  TRANSLATE(HCornerMNX,     hcornerxy[CornerMN][0]) \
  TRANSLATE(HCornerMNY,     hcornerxy[CornerMN][1]) \



using namespace Slb::Salmon::Zgy;

namespace {

  template <class T>
  bool GetGeneric(T& value, const ZgyApi::Generic& gen)
  {
    return gen.get(&value);
  }
  template <>
  bool GetGeneric<std::string>(std::string& value, const ZgyApi::Generic& gen)
  {
    ZgyApi::SimpleString tmp;
    if (!GetGeneric(tmp, gen)) {
      return false;
    }
    value = StdStr(tmp);
    return true;
  }

  template <class T>
  void SetGeneric(const T& value, ZgyApi::Generic& gen)
  {
    gen = ZgyApi::Generic(value);
  }

  template <>
  void SetGeneric<std::string>(const std::string& value, ZgyApi::Generic& gen)
  {
    SetGeneric(ZgyApi::SimpleString(value.c_str()), gen);
  }
}

MyMetaData::MyMetaData()
  : datatype(0), datamin(0), datamax(0),
    zunitdim(ZgyApi::UnitDim::Unknown), zunitname(), zunitfactor(0), z0(0), dz(0),
    hunitdim(ZgyApi::UnitDim::Unknown), hunitname(), hunitfactor(0), 
    other()
{
  // Not all compilers support initializing arrays in the declaration, so do this the old way.
  memset(&size[0],         0, sizeof(size));
  memset(&hannot0[0],      0, sizeof(hannot0));
  memset(&dhannot[0],      0, sizeof(dhannot));
  memset(&hcornerxy[0][0], 0, sizeof(hcornerxy));
}

void MyMetaData::set(const ZgyApi::SimpleString& key, const ZgyApi::Generic& val)
{
#define TRANSLATE(KEY, FIELD) \
  if (key == ZgyApi::MetaDataKey::Get(ZgyApi::MetaDataKey::KEY)) { \
    GetGeneric(FIELD, val); \
    return; \
  }
  TRANSLATE_FIELDS
#undef TRANSLATE

  // we get here only if key does not refer to any of the explicit fields
  other[StdStr(key)] = val;
}

bool MyMetaData::get(const ZgyApi::SimpleString& key, ZgyApi::Generic* val) const
{
#define TRANSLATE(KEY, FIELD) \
  if (key == ZgyApi::MetaDataKey::Get(ZgyApi::MetaDataKey::KEY)) { \
    SetGeneric(FIELD, *val); \
    return true; \
  }
  TRANSLATE_FIELDS
#undef TRANSLATE

  // we get here only if key does not refer to any of the explicit fields
  std::map<std::string, ZgyApi::Generic>::const_iterator it(other.find(StdStr(key)));
  if (it == other.end()) {
    return false;
  }
  *val = it->second;
  return true;
}
