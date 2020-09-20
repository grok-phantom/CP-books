/*
 * A graph is bipartite if its nodes can be colored using two colors
 * so that there are no adjacent nodes with the same color.
 * The idea is to color the starting node blue, all its neighbors red,
 * all their neighbors blue, and so on. If at some point of the search
 * we notice that two adjacent nodes have the same color, this means
 * that the graph is not bipartite.
 */
#include <iostream>
#include <vector>

constexpr int N = 5;
std::vector<int> adj[N+1];
bool visited[N+1];
bool red_color[N+1];

bool dfs(int x, bool is_red){
  if(visited[x]){
    return red_color[x]==is_red;
  }
  visited[x] = true;
  red_color[x] = is_red;
  for(auto u:adj[x]){
    if(!dfs(u, !is_red))
      return false;
  }
  return true;
}

bool bipartiteness_check(){
  return dfs(1, false);
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
  adj[4].push_back(5);
  adj[5].push_back(2);
  adj[5].push_back(3);
  adj[5].push_back(4);


  if(bipartiteness_check())
    std::cout<< "Bipartite" << std::endl;
  else
    std::cout<< "No bipartite" << std::endl;

  return 0;
}
