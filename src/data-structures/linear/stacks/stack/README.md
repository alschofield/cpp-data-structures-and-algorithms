# Stack

## Implementation Model
An array-backed last-in, first-out collection keeps its top at `size - 1` and grows geometrically as needed.

## Public Contract
`template<class T> class Stack` with `Push(T) -> bool`, `Pop() -> std::optional<T>`, `Peek() -> std::optional<T>`, `Size()`, and `Empty()`.

## Semantics And Invariants
Push appends at the top; Pop and Peek return the newest value, with only Pop removing it. Empty Pop and Peek return no value and leave state unchanged. The stack owns its storage, not values held by pointer-like `T`.

## C++ Ownership And Failures
The stack owns its contiguous storage and stored `T` values. Passing `T` by value permits moves into `Push`; `Pop` and `Peek` return owned optional values, not references into storage. RAII must release storage and preserve the top and size invariants if allocation or element construction throws. Do not add a sentinel or exception-based empty-state API.

## Complexity
Push amortized O(1); Pop, Peek, Size, Empty O(1); O(n) contiguous space.

## Verification
`test_stack.cpp` currently verifies that `stack.hpp` is includable. Add behavioral coverage for LIFO order, empty reads, growth, and move-only or throwing `T` values.
