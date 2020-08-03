cmake_minimum_required(VERSION 3.10)

project(starter_cpp VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Options
option(ENABLE_PCH   "Enable Precompiled Headers" OFF)
option(ENABLE_TESTS "Enable tests" OFF)
option(ENABLE_CONAN "Enable Conan" OFF)

# Link to use the warnings specified in CompilerWarnings.cmake
add_library(project_options INTERFACE)
# standard compiler warnings
include(cmake/CompilerOptions.cmake)
set_project_options(project_options)

# Sources common for all platforms .cpp .hpp
set(SOURCES
  src/main.cpp
  src/Foo/Foo.cpp
  # src/other.cpp
)

# Get the headers
set(INCLUDES include include/Foo)
include_directories(PUBLIC ${INCLUDES})
# target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})

# setup file extensions for platform specific sources: Linux, Windows, and Apple (Darwin)
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux") # .cc .hh
  set(PLATFORM_EXTENSION cc)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows") # .cxx .hxx
  set(PLATFORM_EXTENSION cxx)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # .mm .h
  set(PLATFORM_EXTENSION mm)
endif()

set(SOURCES ${SOURCES} src/Foo/Foo.${PLATFORM_EXTENSION})

message("Platform: ${CMAKE_SYSTEM_NAME}")

#--
if(ENABLE_PCH)
  # Since CMake 3.16, maybe 3.15?
  #  target_precompile_headers(project_options INTERFACE <vector> <string> <map> <utility>)
endif()

if(ENABLE_TESTS)
  enable_testing()
  add_subdirectory(test)
elseif()
  message("Tests not included")
endif()

if(ENABLE_FUZZ_TESTS)
#  enable_testing()
  add_subdirectory(fuzz_test)
elseif()
  message("Fuzz Tests not included")
endif()

if (ENABLE_CONAN)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})

if (ENABLE_CONAN)
  target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
endif ()

# target_compile_features(starter_cpp PRIVATE cxx_lambda_init_captures)
