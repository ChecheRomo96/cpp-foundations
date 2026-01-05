cmake_minimum_required(VERSION 3.16)
project(CppFoundations LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_TESTING "Enable unit tests" ON)
option(ENABLE_COVERAGE "Enable coverage flags" OFF)

# Coverage flags (GCC/Clang)
if(ENABLE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Coverage enabled")
    add_compile_options(-O0 -g --coverage)
    add_link_options(--coverage)
  else()
    message(WARNING "Coverage requested but compiler is not GNU/Clang")
  endif()
endif()

add_library(FoundationsLib
  student/src/MathUtils.cpp
)

target_include_directories(FoundationsLib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/student/include
)

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

  target_include_directories(UnitTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/student/include
)

  target_link_libraries(UnitTests
    PRIVATE
      FoundationsLib
      GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(UnitTests)
endif()
