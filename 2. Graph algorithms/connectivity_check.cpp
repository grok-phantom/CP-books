/*
 * A graph is connected iif there is a path between any
 * two nodes of the graph. Thus, we can check if a graph
 * is connected by starting at an arbitrary node and
 * finding out if we can reach all other nodes.
 */
#include <iostream>
#include <vector>

constexpr int N = 5;
std::vector<int> adj[N+1];
bool visited[N+1];

void dfs(int x){
  if(visited[x]) return;
  visited[x] = true;
  for(auto u:adj[x])
    dfs(u);
}

bool connectivity_check(){
  dfs(1);
  for (int kI = 1; kI < N; ++kI) {
    if (!visited[kI]) return false;
  }
  return true;
}


int main(){
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[3].push_back(1);
  adj[3].push_back(4);
  adj[4].push_back(1);
  adj[4].push_back(3);
  adj[2].push_back(2);
  adj[5].push_back(2);

  if (connectivity_check()){
    std::cout<<"Connectivity"<<std::endl;
  }else
    std::cout<<"No connectivity"<<std::endl;

  return 0;
}
