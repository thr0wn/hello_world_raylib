[![](https://img.shields.io/badge/c++-black?logo=c++&style=for-the-badge)](https://learnxinyminutes.com/c++/)

<img width="292" height="299" alt="image" src="https://github.com/user-attachments/assets/616d8d02-45d5-48fc-b845-8965b50eed12" />

## Hello World in C++
Just a cpp hello world with raylib built with cmake.

### Build
```shell
export CC=/usr/bin/gcc
export CXX=/usr/bin/g++
cmake -S . -B ./build
cmake --build build
```

### Run
```shell
./build/hello-world/exe
```

### Debug
```shell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
gdb ./build/hello-world/exe
```

### Tests
```shell
cmake -S . -B build
cmake --build build --target unit-tests
./build/tests/unit-tests
```

### Watch with nodemon
```shell
npx nodemon --exec "cmake -S . -B build && cmake --build build && ./build/hello-world/exe" --watch src -e cpp,hpp,txt
```
