# Data Structures and Algorithms in C++

This repository mirrors the canonical C curriculum's 27-leaf taxonomy. Each
leaf contains an idiomatic C++ API contract and a test scaffold. Implement
the production API from first principles; do not replace an exercise with a
standard-library container or algorithm.

## Taxonomy

```text
src/data-structures/linear/arrays/dynamic-array
src/data-structures/linear/stacks/stack
src/data-structures/linear/queues/queue
src/data-structures/linear/linked/singly-linked-list
src/data-structures/linear/linked/doubly-linked-list
src/data-structures/associative/hash-tables/separate-chaining
src/data-structures/trees/binary-search-trees/binary-search-tree
src/data-structures/trees/tries/prefix-trie
src/data-structures/trees/heaps/binary-heap
src/data-structures/graphs/graph-view
src/data-structures/graphs/representations/adjacency-list
src/data-structures/graphs/representations/adjacency-matrix
src/data-structures/graphs/disjoint-sets/union-find
src/algorithms/searching/linear-search
src/algorithms/searching/binary-search
src/algorithms/sorting/comparison/bubble-sort
src/algorithms/sorting/comparison/selection-sort
src/algorithms/sorting/comparison/insertion-sort
src/algorithms/sorting/comparison/merge-sort
src/algorithms/sorting/comparison/quick-sort
src/algorithms/sorting/comparison/heap-sort
src/algorithms/sorting/non-comparison/counting-sort
src/algorithms/sorting/non-comparison/radix-sort
src/algorithms/graph-traversal/breadth-first-search
src/algorithms/graph-traversal/depth-first-search
src/algorithms/shortest-paths/dijkstra
src/algorithms/shortest-paths/a-star
```

## Commands

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Tests intentionally include the production headers you will create, so builds
fail until the corresponding API exists.
