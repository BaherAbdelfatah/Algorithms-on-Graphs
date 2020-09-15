#include <iostream>
#include <vector>

using namespace std;
vector<bool> visited;
vector<bool> recStack;
vector<vector<int>> adj;

int isCyclicUtil(int v)
{
	if(visited[v]==false)
	{
		visited[v]=true;
		recStack[v]=true;
		for(int i=0;i<adj[v].size();i++)
		{
			if(!visited[adj[v][i]]&&isCyclicUtil(adj[v][i]))
				return true;
			else if(recStack[adj[v][i]])
				return true;
		}
	}
	recStack[v]=false;
	return false;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
	for(int i=0;i<adj.size();i++)
	{
		if(isCyclicUtil(i))
			return 1;
	}
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  adj=vector<vector<int>>(n, vector<int>());
  visited=vector<bool>(n,false);
  recStack=vector<bool>(n,false);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}