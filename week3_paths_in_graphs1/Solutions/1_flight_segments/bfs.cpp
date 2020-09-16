#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
vector<int>dist;
int inf;
void BFS(int s)
{
	dist[s]=0;
	queue<int>Q;
	Q.push(s);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			if(dist[adj[u][i]]==inf)
			{
				Q.push(adj[u][i]);
				dist[adj[u][i]]=dist[u]+1;
			}
		}
	}
}
int distance( int s, int t) {
  //write your code here
	BFS(s);
	if(dist[t]==inf)
		return -1;
	else
		return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  adj=vector<vector<int>>(n, vector<int>());
  inf=m+n+1;
  dist=vector<int>(n,inf);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(s, t);
}