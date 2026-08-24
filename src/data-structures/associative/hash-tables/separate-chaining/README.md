# Hash Table

## How It Works
A hash chooses a bucket and collisions form linked chains. `Set` preserves the
chosen fixed capacity; `SetResizing` doubles and rehashes buckets before a new
entry would exceed a 0.75 load factor.

## Required API
`template<class Key, class Value, class Hash, class Equal> class HashTable`
with an explicit constructor accepting `Hash`, `Equal`, and a nonzero initial
capacity; `Set(key, value) -> std::optional<Value>`,
`SetResizing(key, value) -> std::optional<Value>`,
`Get(key) -> std::optional<Value>`, `Remove(key) -> std::optional<Value>`,
`Contains(key)`, `Size`, `Capacity`, and `Empty`.

## Contract
- The constructor requires a nonzero initial capacity. Standard callers use
  `10`; an invalid capacity must be rejected without creating a table.
- Both set methods insert a new key or replace an equal key's value, retaining
  the first stored key. Their return value is the prior value when replaced.
- `Set` never changes capacity.
- `SetResizing` checks whether adding a new key would exceed a 0.75 load
  factor. If so, it doubles capacity and rehashes every entry with
  `hash(key) % new_capacity` before insertion. A failed allocation preserves
  the table, capacity, and result.
- `Get` and `Remove` report absence without mutation. Colliding distinct keys
  remain correct. Values must support an explicit absent state distinct from
  stored null-like values. Do not use `std::unordered_map`.

## Complexity Targets
`Set`, `Get`, `Remove`, and `Contains` are expected O(1) with short chains,
O(n / capacity) as fixed chains grow, and O(n) worst case. `SetResizing` is
expected amortized O(1) and O(n) when resizing. `Size`, `Capacity`, and
`Empty` are O(1); space is O(entries + capacity).
