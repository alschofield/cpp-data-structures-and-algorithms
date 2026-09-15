# Queue

## Implementation Model
An array-backed FIFO collection uses wrapping head and tail indexes, avoiding shifts on dequeue.

## Public Contract
`template<class T> class Queue` with `Enqueue(T) -> bool`, `Dequeue() -> std::optional<T>`, `Peek() -> std::optional<T>`, `Size()`, and `Empty()`.

## Semantics And Invariants
Enqueue adds at the back; Dequeue and Peek return the oldest value; only Dequeue removes it. Empty reads return no value without mutation. Use a resizable ring buffer, not `std::queue` or another library container.

## C++ Ownership And Failures
The queue owns its resizable ring-buffer storage and stored `T` values. Passing `T` by value permits moves into `Enqueue`; `Dequeue` and `Peek` return owned optional values, not references into storage. RAII must release storage and preserve head, tail, size, and empty-state invariants if allocation, move, or construction throws. Do not use `std::queue` or introduce another empty-state API.

## Complexity
Enqueue amortized O(1); Dequeue, Peek, Size, Empty O(1); O(n) contiguous space.

## Verification
`test_queue.cpp` currently verifies that `queue.hpp` is includable. Add coverage for FIFO order across wraparound and growth, empty reads, and move-only or throwing element types.
