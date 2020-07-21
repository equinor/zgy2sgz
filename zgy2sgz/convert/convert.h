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
