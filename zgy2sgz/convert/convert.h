/** Copyright 2020 Equinor
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

#include <Salmon/Zgy/Api/Api.h>
#include <Salmon/Zgy/Api/Example/meta.h>
#include <Salmon/Zgy/Api/Example/utils.h>

#include <iostream>
#include <stdlib.h>

using namespace Slb::Salmon::Zgy;

#define ZGYAPI_ASSERT(statement) \
    if (!(statement)) { \
        std::cout << "error in ZGY-API: " << #statement << ": " << error.getFullMsg() << std::endl; \
        return; \
    }

#ifdef _WIN32
#  define MODULE_API __declspec(dllexport)
#else
#  define MODULE_API
#endif

MODULE_API void convertFile(const char *infile, const char *outfile, int bits_per_voxel);
void writeHeader(std::ofstream& outfile_handle, MyMetaData meta, int size_pad[3], int pad_dim, int bits_per_voxel);
void writeFooter(std::ofstream& outfile_handle, MyMetaData meta);
