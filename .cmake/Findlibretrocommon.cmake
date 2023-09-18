# libretro-common
include(FetchContent)
FetchContent_Declare(
    libretrocommon
    GIT_REPOSITORY https://github.com/libretro/libretro-common.git
    GIT_TAG 01c6122931a10a7012973054e7067859d2116420
    GIT_SHALLOW 1
)
FetchContent_MakeAvailable(libretrocommon)
#include_directories(${libretrocommon_SOURCE_DIR})
