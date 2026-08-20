# Radix Sort

## How It Works
Apply a stable counting sort to successive least-significant fixed-radix digits.

## Required API
`bool RadixSort(std::span<uint32_t> items)`.

## Contract
Process least to most significant digits with stable per-digit counting sorts. Reuse auxiliary storage where practical; allocation failure leaves input unchanged. Do not use comparisons or a library sort.

## Complexity Targets
Best/average/worst O(d(n+k)), O(n+k) auxiliary space.
