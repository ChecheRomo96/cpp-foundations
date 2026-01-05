# cpp-foundations

C++ foundations repo with:

- CMake
- GoogleTest (gtest)
- Coverage: gcov + lcov
- GitHub Actions CI

## Student work policy

You must only modify files under:

- `student/**`

Any modification outside `student/` will fail CI.

## Local build + test

```bash
cmake -S . -B build -DENABLE_TESTING=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build
cd build
ctest --output-on-failure
```

## CI coverage report

GitHub Actions generates an HTML coverage report and uploads it as an artifact named coverage_html.
Download it from the Actions run and open index.html.

## Header policy

This repository uses classic include guards:

- #ifndef
- #define
- #endif

Do not use #pragma once in headers for this course stage.
