#include "adjacency_matrix.hpp"

void AcceptGraphView(const GraphView&) {}

void AdjacencyMatrixAdaptsToGraphView(const AdjacencyMatrix& graph) {
  AcceptGraphView(graph.AsGraphView());
}

int main() {}
