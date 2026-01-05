cmake_minimum_required(VERSION 3.16)
project(CppFoundations LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTING "Enable unit tests" ON)
option(ENABLE_COVERAGE "Enable coverage flags" OFF)

# -----------------------------
# Library
# -----------------------------
add_library(FoundationsLib
  student/src/MathUtils.cpp
)

target_include_directories(FoundationsLib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/student/include
)

# -----------------------------
# Tests
# -----------------------------
if(ENABLE_TESTING)
  include(CTest)
  enable_testing()

  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  add_executable(UnitTests
    tests/test_math_utils.cpp
  )

  target_link_libraries(UnitTests PRIVATE
    FoundationsLib
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(UnitTests)
endif()

# -----------------------------
# Coverage (apply to targets)
# -----------------------------
if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  message(STATUS "Coverage enabled")

  target_compile_options(FoundationsLib PRIVATE -O0 -g --coverage)
  target_link_options(FoundationsLib PRIVATE --coverage)

  if(TARGET UnitTests)
    target_compile_options(UnitTests PRIVATE -O0 -g --coverage)
    target_link_options(UnitTests PRIVATE --coverage)
  endif()
endif()
