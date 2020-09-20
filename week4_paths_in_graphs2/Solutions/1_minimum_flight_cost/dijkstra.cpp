#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

class myComparator 
{ 
public: 
    int operator() (const pair<int,int>& p1, const pair<int,int>& p2) 
    { 
		return p1.first > p2.first; 
    } 
}; 

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
	int V=adj.size();
	vector<int>dist(V,INF);
	vector<int>prev(V,-1);
	dist[s]=0;
	priority_queue <pair<int,int>,vector<pair<int,int>>,myComparator> H;
	H.emplace(0,s);
	while(!H.empty())
	{
		int u=(H.top()).second;
		H.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(dist[v]>dist[u]+cost[u][i])
			{
				dist[v]=dist[u]+cost[u][i];
				prev[v]=u;
				H.emplace(dist[v],v);
			}
		}
	}
	if(dist[t]==INF)
		return -1;
	else
		return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}