# Counting Sort

## Implementation Status

Target scaffold. Production behavior is not claimed until the learner-owned implementation and its verification are complete.

## How It Works

Count integer keys in `[0, key_limit)`, prefix-sum counts, then place input stably into an output buffer.

Count occurrences in a bounded integer-key range, then place values using cumulative counts.

## Required API

`bool CountingSort(std::span<uint32_t> items, uint32_t key_limit)`.

## Contract

Use no comparisons. Validate all keys before mutating; allocation or invalid input leaves items unchanged. Use reverse placement or equivalent stability-preserving placement. Do not use a library sort.

`std::span<uint32_t>` is a non-owning mutable view, so the algorithm writes caller-owned values and retains no storage. `key_limit` defines the valid half-open key range and is not an inferred API. Validate every key before allocating output or mutating input; allocation or validation failure leaves input unchanged. The documented `bool` return is the only failure channel.

## Complexity Targets

Best/average/worst O(n+k), O(n+k) auxiliary space.

Target: O(n + k) time and O(n + k) space for key range k; stable.

## Verification

`test_counting_sort.cpp` currently verifies that `counting_sort.hpp` is includable. Add coverage for empty input, zero and maximum valid keys, invalid keys, stability, and allocation failure without mutation.
