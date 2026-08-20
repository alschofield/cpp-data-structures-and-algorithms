# Stack

## How It Works
An array-backed last-in, first-out collection keeps its top at `size - 1` and grows geometrically as needed.

## Required API
`template<class T> class Stack` with `Push(T) -> bool`, `Pop() -> std::optional<T>`, `Peek() -> std::optional<T>`, `Size()`, and `Empty()`.

## Contract
Push appends at the top; Pop and Peek return the newest value, with only Pop removing it. Empty Pop and Peek return no value and leave state unchanged. The stack owns its storage, not values held by pointer-like `T`.

## Complexity Targets
Push amortized O(1); Pop, Peek, Size, Empty O(1); O(n) contiguous space.
