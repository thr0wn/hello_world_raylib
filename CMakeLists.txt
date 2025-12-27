cmake_minimum_required(VERSION 3.5.0)
project(hello_world VERSION 1.0.0)

include(FetchContent)

# build type and others
# ----------------------------------------------------------------------------------------
set(CMAKE_BUILD_TYPE Debug)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# c standard
# ----------------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# compile options
# ----------------------------------------------------------------------------------------
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU") 
  add_compile_options(
    -Wall
    -Wno-enum-compare
    -Wno-error=maybe-uninitialized
  )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_compile_options(/W4)
endif()

# dependencies
# ----------------------------------------------------------------------------------------
# Dependency: raylib
set(RAYLIB_VERSION 5.0)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib
  GIT_TAG ${RAYLIB_VERSION}
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raylib)

# Dependency: raygui (no root CMakeList.txt)
set(RAYGUI_VERSION 4.0)
FetchContent_Declare(
  raygui
  GIT_REPOSITORY https://github.com/raysan5/raygui
  GIT_TAG ${RAYGUI_VERSION}
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(raygui)
add_subdirectory("${raygui_SOURCE_DIR}/projects/CMake")

# library setup
# ----------------------------------------------------------------------------------------
set(LIBRARY_NAME game-lib)
add_library(${LIBRARY_NAME} STATIC
  "${CMAKE_SOURCE_DIR}/src/lib/hello-world.cpp"
  "${CMAKE_SOURCE_DIR}/src/lib/hello-world.hpp"
)
target_link_libraries(${LIBRARY_NAME} PUBLIC
  raylib
  raygui
)
target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/src")

# executable setup
# ----------------------------------------------------------------------------------------
set(EXECUTABLE_NAME exe)
add_executable(${EXECUTABLE_NAME}
  "${CMAKE_SOURCE_DIR}/src/main.cpp"
)
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)

# config file
# ----------------------------------------------------------------------------------------
configure_file(
  "${CMAKE_SOURCE_DIR}/src/config/config.h.in"
  "${CMAKE_BINARY_DIR}/config/config.h" ESCAPE_QUOTES
)
target_include_directories(${LIBRARY_NAME} PUBLIC "${CMAKE_BINARY_DIR}")
