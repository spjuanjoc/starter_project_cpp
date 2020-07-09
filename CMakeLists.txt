cmake_minimum_required(VERSION 3.10)

project(starter_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(ENABLE_TESTS "Enable googletest" OFF)

## \todo Add optimization flags
## \todo Replace compiler identification
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message("using Clang")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
#    set(${CMAKE_CXX_COMPILER} "g++")
    add_compile_options(-O3)
    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    message("using Intel C++")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message("using Visual Studio C++")
    add_compile_options(/W4)
endif ()
message("Compiler: ${CMAKE_CXX_COMPILER}")
message("Compiler ID: ${CMAKE_CXX_COMPILER_ID}")

#
set(SOURCES
        main.cpp
        # other.cpp
        )

# To get the headers
include_directories(PUBLIC include)

if (ENABLE_TESTS)
    #  set(SOURCES
    #          ${SOURCES}
    #          test/Module.cpp
    #      )

    include_directories(test/Module)

    #  add_definitions(-DGTEST_LANGUAGE_CXX11)
    enable_testing()
    add_executable(tester test/Module)
    add_test(Tester tester)
#  # Link googletest with the current project
#  #target_link_libraries(${PROJECT_NAME} gtest gmock )
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})

#target_compile_features(starter_cpp PRIVATE cxx_lambda_init_captures)
