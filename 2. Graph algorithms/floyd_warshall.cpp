/*
 * The Floyd-Warshall algorithm provides an alternative way to approach
 * the problem of finding shortest paths. Unlike the other algorithms of
 * this chapter, it finds all shortest paths between the nodes in a single
 * run.
 * The algorithm maintains a two-dimensional array that contains distances
 * between the nodes. First, distances are calculated only using direct
 * edges between the nodes, and after this, the algorithm reduces distances
 * by using intermediate nodes in paths.
 */

#include <iostream>
#include <vector>
typedef long long ll;
constexpr int N = 5;
std::vector<std::vector<ll>> adj{{0, 5, -1, 9, 1},
                                  {5, 0, 2, -1, -1},
                                  {-1, 2, 0, 7, -1},
                                  {9, -1, 7, 0, 2},
                                  {1, -1, -1, 2, 0}};
std::vector<std::vector<ll>> distance(N, std::vector<ll>(N));

// O(n*3)
void floyd_warshall() {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        distance[i][j] = std::min(distance[i][j],
                                  distance[i][k] + distance[k][j]);
      }
    }
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) distance[i][j] = 0;
      else if (adj[i][j] > 0) distance[i][j] = adj[i][j];
      else distance[i][j] = INT_MAX;
    }
  }
  floyd_warshall();
  std::cout << distance[0][2] << std::endl;
}
