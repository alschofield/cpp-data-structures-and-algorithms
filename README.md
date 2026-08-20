# Data Structures and Algorithms in C++

This repository mirrors the canonical C curriculum's 27-leaf taxonomy. Each
leaf contains an idiomatic C++ API contract and a test scaffold. Implement
the production API from first principles; do not replace an exercise with a
standard-library container or algorithm.

## Commands

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Tests intentionally include the production headers you will create, so builds
fail until the corresponding API exists.
