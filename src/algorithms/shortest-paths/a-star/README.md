# A-Star

## How It Works
The min-priority frontier is ordered by `f = g + h`, combining travelled cost with an admissible goal estimate.

## Required API
`std::optional<std::vector<size_t>> AStar(const GraphView&, size_t source, size_t goal, Heuristic heuristic)`, where `Heuristic` accepts a vertex index.

## Contract
Reject out-of-range source and goal indexes; GraphView edge weights are nonnegative. With zero heuristic, match Dijkstra behavior. Resolve frontier ties deterministically, return an optimal reconstructed index path for admissible heuristics, and return no path when exhausted. Do not use a library pathfinding routine.

## Complexity Targets
Worst O((V+E) log V) time and O(V) space.
