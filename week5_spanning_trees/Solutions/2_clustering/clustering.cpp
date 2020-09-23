#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std; 

class Edge  
{  
    public: 
    int src, dest;
	double weight;  
	Edge(){}
	Edge(int s,int d,double w)
	{
		src=s;
		dest=d;
		weight=w;
	}
};
double distance(int x1, int y1, int x2, int y2) 
{ 
    // Calculating distance 
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
} 

class subset  
{  
    public: 
    int parent;  
    int rank;  
};  
  
// A utility function to find set of an element i  
// (uses path compression technique)  
int find(subset subsets[], int i)  
{  
    // find root and make root as parent of i  
    // (path compression)  
    if (subsets[i].parent != i)  
        subsets[i].parent = find(subsets, subsets[i].parent);  
  
    return subsets[i].parent;  
}  
  
// A function that does union of two sets of x and y  
// (uses union by rank)  
void Union(subset subsets[], int x, int y)  
{  
    int xroot = find(subsets, x);  
    int yroot = find(subsets, y);  
  
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank)  
    if (subsets[xroot].rank < subsets[yroot].rank)  
        subsets[xroot].parent = yroot;  
    else if (subsets[xroot].rank > subsets[yroot].rank)  
        subsets[yroot].parent = xroot;  
  
    // If ranks are same, then make one as root and  
    // increment its rank by one  
    else
    {  
        subsets[yroot].parent = xroot;  
        subsets[xroot].rank++;  
    }  
}  
  
// Compare two edges according to their weights.  
// Used in qsort() for sorting an array of edges  
int myComp(Edge a, Edge b)  
{    
    return a.weight < b.weight;  
}  

int myComp_desc(Edge a, Edge b)  
{    
    return a.weight > b.weight;  
}
  
// The main function to construct MST using Kruskal's algorithm  
double KruskalMST(vector<Edge> &edges,int &V,int &k)  
{  
	vector<Edge> result(V);
	int e = 0; // An index variable, used for result[]  
    int i = 0; // An index variable, used for sorted edges 
	sort(edges.begin(), edges.end(), myComp);  
    // Allocate memory for creating V ssubsets  
    subset *subsets = new subset[( V * sizeof(subset) )];   
    // Create V subsets with single elements  
    for (int v = 0; v < V; ++v)  
    {  
        subsets[v].parent = v;  
        subsets[v].rank = 0;  
    }  
	int E=edges.size();
    // Number of edges to be taken is equal to V-1  
    while (e < V - 1 && i < E)  
    {  
        // Step 2: Pick the smallest edge. And increment  
        // the index for next iteration  
        Edge next_edge = edges[i++];  
  
        int x = find(subsets, next_edge.src);  
        int y = find(subsets, next_edge.dest);  
  
        // If including this edge does't cause cycle,  
        // include it in result and increment the index  
        // of result for next edge  
        if (x != y)  
        {  
            result[e++] = next_edge;  
            Union(subsets, x, y);  
        }  
			if(e > V - k) return next_edge.weight;
    }  
} 

double minimum_distance(vector<int> &x, vector<int> &y,int k) {
  double result = 0.;
  //write your code here
  int V=x.size();
  vector<Edge> edges;
  for(int i=0;i<V;i++)
  {
	  for(int j=0;j<V;j++)
	  {
		  if(i==j)
			  continue;
		  double d=distance(x[i],y[i],x[j],y[j]);
		  edges.emplace_back(i,j,d);
		  edges.emplace_back(j,i,d);
	  }
  }
  return KruskalMST(edges,V,k);
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  int k;
  cin>>k;
  std::cout << std::setprecision(10) << minimum_distance(x, y, k) << std::endl;
}