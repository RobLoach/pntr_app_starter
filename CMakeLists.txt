cmake_minimum_required(VERSION 3.11)
project(pntr_app_starter
    DESCRIPTION "pntr_app_starter"
    HOMEPAGE_URL "https://github.com/robloach/pntr_app_starter"
    VERSION 0.0.1
    LANGUAGES C
)

# Targets
option(SDL "Build SDL" TRUE)
option(RAYLIB "Build raylib" TRUE)
option(LIBRETRO "Build libretro" TRUE)
option(CLI "Build CLI" TRUE)
option(WEB "Build Web" TRUE)

# Sources
set(SOURCES
    src/main.c
)

# Libraries
#list(APPEND LIBRARIES mycustomlibrary)

# Have pntr_app_starter build the project
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/.cmake")
find_package(pntr_app_starter)
