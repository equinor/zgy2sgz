#pragma once
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

#include <Salmon/Zgy/Api/MetaDataProvider.h>
#include <Salmon/Zgy/Api/MetaDataReceiver.h>
#include <Salmon/Zgy/Api/Generic.h>

#include <string>
#include <map>

/** Example implementation of MetaDataProvider and -Receiver. */
class MyMetaData
  : virtual public Slb::Salmon::Zgy::ZgyApi::MetaDataProvider,
    virtual public Slb::Salmon::Zgy::ZgyApi::MetaDataReceiver
{
public:

  /** Corner indices. */
  enum
  {
    Corner00, // Lowest inline, lowest crossline.
    CornerM0, // Highest inline, lowest crossline.
    Corner0N, // Lowest inline, highest crossline.
    CornerMN  // Highest inline, highest crossline.
  };


  // **** explicit fields ***
  // basics
  int         size[3];          /** Size of seismic cube. */
  int         datatype;         /** Datatype, one of the DataType enums in MetaDataValue.h. */
  float       datamin;          /** Minimum data value. Serves as lower clipping value if datatype is integral. */
  float       datamax;          /** Maximum data value. Serves as upper clipping value if datatype is integral. */

  // vertical domain info
  int         zunitdim;         /** Vertical unit dimension, one of the UnitDim enums in MetaDataValue.h. */
  std::string zunitname;        /** Name of vertical unit, e.g. "ms", "m" or "ft". */
  double      zunitfactor;      /** Scaling factor of vertical unit, e.g. 0.001 for ms, 1.0 for m or 0.3048 for ft. */
  float       z0;               /** Distance from surface/MSL to first sample, given in the vertical unit. */
  float       dz;               /** Sample interval, given in the vertical unit. */

  // horizontal domain info
  float       hannot0[2];       /** First inline and crossline numbers. */
  float       dhannot[2];       /** Inline and crossline number increments between adjacent sections of the cube. */
  int         hunitdim;         /** Horizontal unit dimension, one of the UnitDim enums in MetaDataValue.h. */
  std::string hunitname;        /** Name of horizontal unit, e.g. "m" or "ft". */
  double      hunitfactor;      /** Scaling factor of vertical unit, e.g. 1.0 for m or 0.3048 for ft. */
  double      hcornerxy[4][2];  /** Easting/northing coordinates of each corner of the cube. See Corner?? enum above for ordering. */


  // *** other fields ***
  std::map<std::string, Slb::Salmon::Zgy::ZgyApi::Generic> other;  /** Any remaining entries which are not explicitly used. */


  // *** methods ***
  MyMetaData();
  virtual void set(const Slb::Salmon::Zgy::ZgyApi::SimpleString& key, const Slb::Salmon::Zgy::ZgyApi::Generic& val);
  virtual bool get(const Slb::Salmon::Zgy::ZgyApi::SimpleString& key, Slb::Salmon::Zgy::ZgyApi::Generic* val) const;
};
