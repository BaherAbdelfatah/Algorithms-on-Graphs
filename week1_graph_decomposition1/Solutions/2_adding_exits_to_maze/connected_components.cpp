#include <iostream>
#include <vector>

using std::vector;
using std::pair;
vector<bool> visited;
vector<vector<int>> adj;
void explore(int v)
{
	visited[v]=true;
	for(int i=0;i<adj[v].size();i++)
	{
		if(!visited[adj[v][i]])
			explore(adj[v][i]);
	}
}
int number_of_components() {
  //write your code here
	int cc=0;
	for(int i=0;i<visited.size();i++)
	{
		if(!visited[i])
		{	
			explore(i);
			cc++;
		}
	}
	return cc;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  adj=vector<vector<int>>(n, vector<int>());
  visited=vector<bool>(n,false);
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components();
}