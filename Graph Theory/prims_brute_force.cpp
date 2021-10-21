#include<bits/stdc++.h>
using namespace std;
void prims(int n ,vector<pair<int,int>> adj[])
{
    int wt[n+1];
    bool mst[n+1];
    int parent[n+1];
    for(int i = 1 ;i<=n;i++)
    {
        wt[i]  = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
        wt[1] = 0 ;
    } 
    for(int i = 0;i<n-1;i++)
    {
        int min = INT_MAX,v;
        for(int u = 1;u<=n;u++)
        {
            if(mst[u]==false && wt[u]<min)
            {
                min = wt[u];v= u;
            }
        }
        mst[v] = true;
        for(auto it :adj[v])
        {
            int nextNode = it.first;
            int nextWt= it.second;
            if(mst[nextNode]==false && nextWt < wt[nextNode])
            {
                parent[nextNode] = v;wt[nextNode] = nextWt;
            }
        }
    }
    for(int i = 2;i<n+1;i++)
    cout<<parent[i]<<" --> "<<i<<"\n";
    
}
int main()
{
  int  n, e,u,v,wt;
  cin>>n>>e;
  vector<pair<int , int>> adj[n+1];
  for(int i = 1;i<=n;i++)
  {
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});
  }
    prims(n,adj);
  return 0;
}