# Queue

## How It Works
An array-backed FIFO collection uses wrapping head and tail indexes, avoiding shifts on dequeue.

## Required API
`template<class T> class Queue` with `Enqueue(T) -> bool`, `Dequeue() -> std::optional<T>`, `Peek() -> std::optional<T>`, `Size()`, and `Empty()`.

## Contract
Enqueue adds at the back; Dequeue and Peek return the oldest value; only Dequeue removes it. Empty reads return no value without mutation. Use a resizable ring buffer, not `std::queue` or another library container.

## Complexity Targets
Enqueue amortized O(1); Dequeue, Peek, Size, Empty O(1); O(n) contiguous space.
