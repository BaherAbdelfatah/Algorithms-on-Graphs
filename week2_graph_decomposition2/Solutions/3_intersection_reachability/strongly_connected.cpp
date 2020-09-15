#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<vector<int>> adj_transpose;
stack<int>Stack;
void fillOrder(int v) 
{ 
    visited[v] = true; 
    for (int i = 0; i < adj[v].size(); i++) 
        if (!visited[adj[v][i]]) 
            fillOrder(adj[v][i]);
	Stack.push(v);
} 

void DFSUtil(int v) 
{ 
    visited[v] = true; 
    for (int i = 0; i < adj_transpose[v].size(); i++) 
        if (!visited[adj_transpose[v][i]]) 
            DFSUtil(adj_transpose[v][i]);
}

void getTranspose()
{
	adj_transpose=vector<vector<int>>(adj.size());
	for(int i=0;i<adj.size();i++)
	{
		for(int j=0;j<adj[i].size();j++)
			adj_transpose[adj[i][j]].push_back(i);
	}
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  visited=vector<bool>(adj.size(),false);
  for(int i=0;i<adj.size();i++)
	  if(visited[i]==false)
		  fillOrder(i);
  getTranspose();  
  visited=vector<bool>(adj.size(),false);
	while (Stack.empty() == false) 
	{ 
		// Pop a vertex from stack 
		int v = Stack.top(); 
		Stack.pop(); 
		
		// Print Strongly connected component of the popped vertex 
		if (visited[v] == false) 
		{ 
			DFSUtil(v);
			result++;
		} 
	} 
  return result;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  adj=vector<vector<int>>(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << number_of_strongly_connected_components(adj);
}