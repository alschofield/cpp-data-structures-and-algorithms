# Dynamic Array

## How It Works
Contiguous storage tracks used size separately from allocated capacity and grows geometrically when insertion requires it.

## Required API
`template<class T> class DynamicArray` with `Get(index) -> std::optional<T>`, `Set(index, value) -> std::optional<T>`, `Insert(index, value) -> bool`, `Remove(index) -> std::optional<T>`, `Size()`, `Capacity()`, and `Empty()`.

## Contract
Element indexes are `[0, Size())`; `Insert` also accepts `Size()`. Failed operations do not mutate contents. Capacity is always at least size and grows geometrically. Implement owned contiguous storage, not `std::vector`.

## Complexity Targets
Get, Set, Size, Capacity, Empty O(1); append amortized O(1); other inserts and remove O(n); O(n) contiguous space.
