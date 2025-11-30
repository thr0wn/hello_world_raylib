[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)

## Hello world
Just a cpp hello world with raylib built with cmake.

### Build
```shell
CXX=g++ cmake -S . -B ./build && cmake --build build
```

### Debug
```shell
CXX=g++ cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug && cmake --build build && gdb ./build/hello_world/hello_world
```

### Run
```shell
./build/hello_world/hello_world
```

### Watch with nodemon
```shell
npx nodemon --exec "cmake -S . -B build && cmake --build build && ./build/hello_world/hello_world" --watch src -e cpp,hpp,txt
```
