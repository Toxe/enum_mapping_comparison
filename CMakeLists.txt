cmake_minimum_required(VERSION 3.14)
project("Enum Mapping Comparison" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(benchmark CONFIG REQUIRED)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    string(REGEX REPLACE " /W[0-4]" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

add_executable(enum_mapping enum_mapping.cpp)
target_compile_features(enum_mapping PUBLIC cxx_std_17)
set_target_properties(enum_mapping PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(enum_mapping PRIVATE benchmark::benchmark)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(enum_mapping PRIVATE -Wall -Wextra -Wmost -pedantic -Wconversion -Wfloat-equal -Wold-style-cast -fcolor-diagnostics)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(enum_mapping PRIVATE /W4)
endif()
