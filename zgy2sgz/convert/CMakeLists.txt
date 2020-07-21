add_library(zgy2sgz SHARED convert.cpp meta.cpp)

find_library(ZFP_LIB zfp REQUIRED
                         PATHS "../../zfp/build/lib64"
                               "../../zfp/build/lib/Release"
                         NO_DEFAULT_PATH)
find_library(ZGY_LIB NAMES "Slb.Salmon.Zgy.so"
                           "Slb.Salmon.Zgy.lib"
                     REQUIRED
                     PATHS "../open-zgy/zgy/Slb.Salmon.ZgyPublic/Lin64_gcc485"
                           "../open-zgy/zgy/Slb.Salmon.ZgyPublic/x64_vs140/Salmon/Main/Release"
                     NO_DEFAULT_PATH)
target_link_libraries(zgy2sgz PUBLIC ${ZFP_LIB} ${ZGY_LIB})

include_directories("../open-zgy/zgy/Slb.Salmon.ZgyPublic/include" "../../zfp/include")
