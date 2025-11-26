[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)

## Hello world
Just a cpp hello world with raylib built with cmake.

### Build
```shell
CXX=g++ cmake -S . -B ./build && cmake --build build
```

### Debug
```shell
CXX=g++ cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build && gdb ./build/hellow_world/hello_world
```

### Run
```shell
./build/hellow_world/hello_world
```
