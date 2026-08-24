#include "adjacency_list.hpp"

void AcceptGraphView(const GraphView&) {}

void AdjacencyListAdaptsToGraphView(const AdjacencyList& graph) {
  AcceptGraphView(graph.AsGraphView());
}

int main() {}
