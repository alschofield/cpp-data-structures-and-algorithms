# Prefix Trie

## Implementation Model
Characters form tree edges; root-to-node paths are prefixes and an end marker distinguishes a key from a waypoint.

## Public Contract
`class PrefixTrie` with `Insert(std::string_view) -> bool`, `Contains(std::string_view)`, `StartsWith(std::string_view)`, `Remove(std::string_view) -> bool`, and `Size`.

## Semantics And Invariants
Duplicate insertion is idempotent. Contains matches complete keys only; StartsWith accepts the empty prefix. Remove clears the marker and prunes only nodes that no remaining key needs. Store no borrowed key buffer and do not use a library map/trie.

## C++ Ownership And Failures
The trie owns its nodes and copied key characters; `std::string_view` is an input view only and must not be retained. RAII must release pruned and remaining nodes exactly once. A failed insertion must not leave an unreachable node, an incorrect terminal marker, or an incorrect size. Do not use a library map or trie.

## Complexity
Insert, Contains, StartsWith, Remove O(m) for key length independent of key count; O(total stored characters) space.

## Verification
`test_prefix_trie.cpp` currently verifies that `prefix_trie.hpp` is includable. Add coverage for empty prefixes, prefix-versus-key distinction, duplicate insertion, pruning shared prefixes, and input lifetime independence.
