#include <iostream>
#include <vector>
#include <queue>

constexpr int N = 6;
std::queue<int> q;
std::vector<int> adj[N+1];
bool visited[N];
int distance[N];

void bfs(int x) {
  visited[x] = true;
  distance[x] = 0;
  q.push(x);
  while (!q.empty()) {
    int s = q.front();
    std::cout << s << ' ';
    q.pop();
    for (auto u:adj[s]) {
      if (visited[u]) continue;
      visited[u] = true;
      distance[u] = distance[s] + 1;
      q.push(u);
    }
  }
}

int main() {
  adj[1].push_back(4);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[2].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(2);
  adj[3].push_back(6);
  adj[4].push_back(1);
  adj[5].push_back(2);
  adj[5].push_back(6);
  adj[6].push_back(3);
  adj[6].push_back(5);
  bfs(1);
  std::cout << std::endl;
  return 0;
}
