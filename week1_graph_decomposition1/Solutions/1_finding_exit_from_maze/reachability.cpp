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
int reach(int x, int y) {
  //write your code here
	explore(x);
	if(visited[y]==true)
		return 1;
  return 0;
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
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(x - 1, y - 1);
}