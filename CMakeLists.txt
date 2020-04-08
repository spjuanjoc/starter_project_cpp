cmake_minimum_required(VERSION 3.10)

project(intro)

set(CMAKE_CXX_STANDARD 17)

option(ENABLE_TESTS "Enable googletest" OFF)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SOURCES
        main.cpp
        # other.cpp
        )

# To get the headers
include_directories(Module)

if (ENABLE_TESTS)
  set(SOURCES
          ${SOURCES}
          test/Module.cpp
      )

  include_directories(test/Module)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")
  add_definitions(-DGTEST_LANGUAGE_CXX11)
  enable_testing()
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})

if (ENABLE_TESTS)
  # Link googletest with the current project
  target_link_libraries(${PROJECT_NAME} gtest gmock )
endif ()

target_compile_features(intro PRIVATE cxx_lambda_init_captures)
