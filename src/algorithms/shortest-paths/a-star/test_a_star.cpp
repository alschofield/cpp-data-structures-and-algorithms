#include "a_star.hpp"

void AStarAcceptsGraphView(const GraphView& graph, size_t source, size_t goal) {
  (void)AStar(graph, source, goal, [](size_t) { return 0; });
}

int main() {}
