cmake_minimum_required(VERSION 3.10)
project(conversion_util)
add_subdirectory(convert)
add_executable(demo main.cpp)
target_link_libraries(demo PUBLIC zgy2sgz)
target_include_directories(zgy2sgz PUBLIC "${PROJECT_BINARY_DIR}"
                          		  "${PROJECT_SOURCE_DIR}/convert"
                          )
include_directories("open-zgy/zgy/Slb.Salmon.ZgyPublic/include" "../zfp/include")
