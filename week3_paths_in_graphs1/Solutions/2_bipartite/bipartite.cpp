#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> adj;
vector<int>color;
int inf;
void BFS()
{
	vector<bool> discovered(adj.size(),false);
	for(int s=0;s<adj.size();s+=(1+adj.size()/8))
	{
		if(discovered[s]==true)
			continue;
		color=vector<int>(adj.size(),-1);
		color[s]=1;
		queue<int>Q;
		Q.push(s);
		while(!Q.empty())
		{
			int u=Q.front();
			discovered[u]=true;
			Q.pop();
			for(int i=0;i<adj[u].size();i++)
			{
				if(color[adj[u][i]]==-1)
				{
					Q.push(adj[u][i]);
					color[adj[u][i]]=-color[u];
				}
				else if(color[adj[u][i]]==color[u])
				{
					cout<<0<<endl;
					return;
				}
			}
		}
	}
	cout<<1<<endl;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  adj=vector<vector<int>>(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  BFS();
}