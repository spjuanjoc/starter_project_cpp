cmake_minimum_required(VERSION 3.10)

project(starter_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Options
option(ENABLE_TESTS "Enable tests" OFF)

# Link to use the warnings specified in CompilerWarnings.cmake
add_library(project_options INTERFACE)
# standard compiler warnings
include(cmake/CompilerOptions.cmake)
set_project_options(project_options)


# Sources common for all platforms
# .cpp .hpp
set(SOURCES
        src/main.cpp
        src/Foo/Foo.cpp
        # src/other.cpp
        )

# Get the headers
include_directories(PUBLIC
        include
        include/Foo)

# setup file extensions for platform specific sources: Linux, Windows, and Apple (Darwin)
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux") # .cc .hh
    set(PLATFORM_EXTENSION cc)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows") # .cxx .hxx
    set(PLATFORM_EXTENSION cxx)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # .mm .h
    set(PLATFORM_EXTENSION mm)
endif ()

#set(SOURCES ${SOURCES}
#        src/Foo/Foo.${PLATFORM_EXTENSION})

message("Platform: ${CMAKE_SYSTEM_NAME}")

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})

#target_compile_features(starter_cpp PRIVATE cxx_lambda_init_captures)
