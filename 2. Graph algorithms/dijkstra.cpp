/*
 * Dijkstra's algorithm finds shortest paths from the starting node
 * to all nodes of the graph, like the Bellman-Ford algorithm. The
 * benefit of Dijkstra's algorithm is that it is more efficient and
 * can be used for processing large graphs. However, the algorithm
 * requires that there are no negative weight edges in the graph.
 */

#include <vector>
#include <iostream>
#include <queue>


constexpr int N = 5;
std::vector<std::pair<int, int>> adj[N+1];
std::vector<int> distance(N+1, INT_MAX);
std::priority_queue<std::pair<int,int>> q; // default is max heap
std::vector<bool> processed(N+1, false);

// O(n + m*log(m))
int dijkstra(int x, int e){
  distance[x] = 0;
  q.push({0, x});
  while(!q.empty()){
    int a = q.top().second; q.pop();
    if(processed[a]) continue;
    processed[a] = true;
    for(auto u : adj[a]){
      int b = u.first, w = u.second;
      if(distance[a]+w < distance[b]){
        distance[b] = distance[a] + w;
        q.push({-distance[b], b});
      }
    }
  }
  return distance[e];
}

int main(){
  adj[1].emplace_back(2, 5);
  adj[1].emplace_back(4, 9);
  adj[1].emplace_back(5, 1);
  adj[2].emplace_back(1, 5);
  adj[2].emplace_back(3,2);
  adj[3].emplace_back(2, 2);
  adj[3].emplace_back(4,6);
  adj[4].emplace_back(1,9);
  adj[4].emplace_back(3, 6);
  adj[4].emplace_back(5, 2);
  adj[5].emplace_back(1,1);
  adj[5].emplace_back(4,2);
  std::cout<<dijkstra(1,3)<<std::endl;
}