/*
 * A graph contains a cycle if during a graph traversal, we find
 * a node whose neighbor (other than the previous node int the
 * current path) has already been visited.
 */
#include <iostream>
#include <vector>

constexpr int N = 5;
std::vector<int> adj[N+1];
bool visited[N+1];


bool dfs(int x){
  if(visited[x]) return true;
  visited[x] = true;
  if(std::any_of(adj[x].begin(), adj[x].end(), dfs))
    return true;
  else
    return false;
}

bool finding_cycle(){
  return dfs(1);
}

int main(){
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[2].push_back(3);
  adj[2].push_back(5);
  adj[3].push_back(1);
  adj[3].push_back(2);
  adj[3].push_back(4);
  adj[3].push_back(5);
  adj[4].push_back(1);
  adj[4].push_back(3);
  adj[5].push_back(2);
  adj[5].push_back(3);
  if (finding_cycle())
    std::cout<<"Find cycle"<<std::endl;
  else
    std::cout<<"Not find cycle"<<std::endl;
  return 0;
}


