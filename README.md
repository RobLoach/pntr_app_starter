# pntr_app_starter

## Native

You can toggle on and off targets by using

```
cmake -B build -DSDL=true -DRAYLIB=true -DLIBRETRO=true -DCLI=true
cmake --build build
```

## Web

```
emcmake cmake -B build -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3" -DCMAKE_EXECUTABLE_SUFFIX=".html"
emmake make -C build
emrun build/index.html
```
