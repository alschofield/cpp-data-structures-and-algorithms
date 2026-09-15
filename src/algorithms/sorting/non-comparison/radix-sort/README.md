# Radix Sort

## Implementation Model
Apply a stable counting sort to successive least-significant fixed-radix digits.

## Public Contract
`bool RadixSort(std::span<uint32_t> items)`.

## Semantics And Invariants
Process least to most significant digits with stable per-digit counting sorts. Reuse auxiliary storage where practical; allocation failure leaves input unchanged. Do not use comparisons or a library sort.

## C++ Value And Failure Semantics
`std::span<uint32_t>` is a non-owning mutable view, so the algorithm writes caller-owned values and retains no storage. Per-digit buffers are algorithm-owned temporary storage and must be released by RAII. Allocate before the first mutation so allocation failure leaves input unchanged. The documented `bool` return is the only failure channel; do not add comparison or library-sort behavior.

## Complexity
Best/average/worst O(d(n+k)), O(n+k) auxiliary space.

## Verification
`test_radix_sort.cpp` currently verifies that `radix_sort.hpp` is includable. Add coverage for empty input, repeated values, zero, maximum `uint32_t`, digit stability, and allocation failure without mutation.
