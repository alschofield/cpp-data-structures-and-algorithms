# Counting Sort

## How It Works
Count integer keys in `[0, key_limit)`, prefix-sum counts, then place input stably into an output buffer.

## Required API
`bool CountingSort(std::span<uint32_t> items, uint32_t key_limit)`.

## Contract
Use no comparisons. Validate all keys before mutating; allocation or invalid input leaves items unchanged. Use reverse placement or equivalent stability-preserving placement. Do not use a library sort.

## Complexity Targets
Best/average/worst O(n+k), O(n+k) auxiliary space.
