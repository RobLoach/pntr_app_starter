# pntr_app_starter

A boilerplate starter project for applications using [pntr](https://github.com/RobLoach/pntr) and [pntr_app](https://github.com/RobLoach/pntr_app).

## Getting Started

Open up [CMakeLists.txt](CMakeLists.txt) and rename the project name from "pntr_app_starter" to your own application name.

``` cmake
project(MyGame
    DESCRIPTION "My Game"
    VERSION 0.0.1
    LANGUAGES C
)
```

## Build

The build process uses [CMake](https://cmake.org/).

### Native

```
cmake -B build -DSDL=true -DRAYLIB=true -DLIBRETRO=true -DCLI=true
cmake --build build
```

### Web

Use the [Emscripten SDK](https://emscripten.org/docs/tools_reference/emsdk.html) to build for the web with raylib.

```
emcmake cmake -B build -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3" -DCMAKE_EXECUTABLE_SUFFIX=".html"
emmake make -C build
emrun build/index.html
```

## License

Unless stated otherwise, all works are:

- Copyright (c) 2023 [Rob Loach](https://robloach.net)

... and licensed under:

- [zlib License](LICENSE)
