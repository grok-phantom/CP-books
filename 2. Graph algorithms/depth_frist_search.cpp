#include <iostream>
#include <vector>

// construct the graph
constexpr int N = 6;
std::vector<int> adj[N];
bool visited[N];

void dfs(int s){
  if(visited[s]) return;
  visited[s] = true;
  std::cout<< s << ' ';
  for(auto u:adj[s]){
    dfs(u);
  }
}

int main(){
  adj[1].push_back(2);
  adj[1].push_back(4);
  adj[2].push_back(1);
  adj[2].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(2);
  adj[3].push_back(5);
  adj[4].push_back(1);
  adj[5].push_back(2);
  adj[5].push_back(3);
  dfs(1);
  std::cout << std::endl;
  return 0;
}