# Data Structures and Algorithms in C++

## Purpose and Status

A language-specific, from-first-principles data-structures-and-algorithms learning curriculum.
Target-scaffold repository. The contracts and test scaffolds define learner-owned production APIs.

## Curriculum Coverage

26 applicable topic leaves. The native dynamic sequence is the baseline rather than a separate exercise.

## Commands

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Conventions

`std::vector` is the allowed native dynamic-sequence baseline when contiguous dynamic storage is needed.
Implement each exercise from first principles; do not replace it with a standard-library container or algorithm.

## Documentation Contract Template

Each topic leaf README uses these sections: `Implementation Status`, `How It Works`, `Required API`, `Contract`, `Complexity Targets`, and `Verification`. The leaf README is authoritative for that topic; source and tests must preserve its language-specific API syntax and stated behavior.

## Repository-Specific Notes

Production implementations are learner-owned. Documentation and verification scaffolding may describe the required work but do not substitute for it.
