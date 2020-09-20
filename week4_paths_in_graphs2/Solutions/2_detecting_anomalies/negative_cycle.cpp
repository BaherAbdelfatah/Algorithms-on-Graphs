#include <iostream>
#include <vector>
#define INF 10000
using namespace std;


int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
	int V=adj.size();
	vector<int>dist(V,INF);
	vector<int>prev(V,-1);
	dist[0]=0;
	for(int i=0;i<adj.size()-1;i++)
	{
		for(int u=0;u<adj.size();u++)
		{
			for(int k=0;k<adj[u].size();k++)
			{
				int v=adj[u][k];
				if(dist[v]>dist[u]+cost[u][k])
				{
					dist[v]=dist[u]+cost[u][k];
					prev[v]=u;
				}
			}
		}
	}
	for(int u=0;u<adj.size();u++)
	{
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(dist[v]>dist[u]+cost[u][i])
			{
				return 1;
			}
		}
	}
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}