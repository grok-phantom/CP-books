/*
 * The **Bellman-Ford algorithm** finds shortest paths from a starting node
 * to all nodes of the graph. The algorithms can process all kinds of graphs,
 * provided that the graph does not contain a cycle with negative graph. If
 * the graph contains a negative cycle, the algorithm can detect this.
 */
#include <iostream>
#include <vector>

constexpr int N = 5;
std::vector<std::pair<int, int>> adj[N + 1];
std::vector<std::tuple<int, int, int>> edges;
std::vector<bool> visited(N + 1,false);
std::vector<int> distance(N+1, INT_MAX);

int bellman_ford(int s, int d) {
  distance[s] = 0;
  for (int i = 1; i < N; ++i) { // n-1 rounds
    for (auto e:edges) {
      int a, b, w;
      std::tie(a, b, w) = e;
      distance[b] = std::min(distance[b], distance[a] + w);
    }
  }
  return distance[d];
}

int main() {
  edges.emplace_back(1, 2, 5);
  edges.emplace_back(1, 3, 3);
  edges.emplace_back(1, 4, 7);
  edges.emplace_back(2, 1, 5);
  edges.emplace_back(2, 4, 3);
  edges.emplace_back(2, 5, 2);
  edges.emplace_back(3, 1, 3);
  edges.emplace_back(3, 4, 1);
  edges.emplace_back(4, 1, 7);
  edges.emplace_back(4, 2, 3);
  edges.emplace_back(4, 3, 1);
  edges.emplace_back(4, 5, 2);
  edges.emplace_back(5, 2, 2);
  edges.emplace_back(5, 4, 2);
  std::cout << bellman_ford(1, 5) << std::endl;
}