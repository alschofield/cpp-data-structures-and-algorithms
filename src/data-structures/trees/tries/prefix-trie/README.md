# Prefix Trie

## How It Works
Characters form tree edges; root-to-node paths are prefixes and an end marker distinguishes a key from a waypoint.

## Required API
`class PrefixTrie` with `Insert(std::string_view) -> bool`, `Contains(std::string_view)`, `StartsWith(std::string_view)`, `Remove(std::string_view) -> bool`, and `Size`.

## Contract
Duplicate insertion is idempotent. Contains matches complete keys only; StartsWith accepts the empty prefix. Remove clears the marker and prunes only nodes that no remaining key needs. Store no borrowed key buffer and do not use a library map/trie.

## Complexity Targets
Insert, Contains, StartsWith, Remove O(m) for key length independent of key count; O(total stored characters) space.
