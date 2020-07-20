add_library(zgy2sgz SHARED convert.cpp meta.cpp)
add_library(ZGY_LIB STATIC IMPORTED)
find_library(ZFP_LIB zfp REQUIRED
                         PATHS "../../zfp/build/lib64")
find_library(ZGY_LIB NAMES "Slb.Salmon.Zgy.so"
                           "Slb.Salmon.Zgy.dll"
                     REQUIRED
                     PATHS "../../open-zgy/zgy/Slb.Salmon.ZgyPublic/Lin64_gcc485"
                           "../../open-zgy/zgy/Slb.Salmon.ZgyPublic/x64_vs140/Salmon/Main/Release")
target_link_libraries(zgy2sgz PUBLIC ${ZFP_LIB} ${ZGY_LIB})

include_directories("../../open-zgy/zgy/Slb.Salmon.ZgyPublic/include", "../../zfp/include")
