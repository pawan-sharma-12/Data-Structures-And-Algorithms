#include<bits/stdc++.h>
using namespace std;
bool dfsCycle(int node,int parent,vector<int> adj[],vector<int> &visited)
{
    visited[node] =1;
    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            if(dfsCycle(it,node,adj,visited)) return true;
            
        }
        else if (it!= parent) return true;
    }
    return false;
}
bool isCycle(int n , vector<int> adj[])
{
    vector<int> visited(n+1,0);
    for(int i = 1;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfsCycle(i,-1,adj,visited)) return true;
        }
    }
    return false;
}
int main()
{
  int n ,e ,u,v;
  cin>>n>>e;
  vector<int> adj[n+1];
  for(int i = 0 ;i<e;i++)
  {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
  }
  if(isCycle(n , adj))
   cout<<"there is a cycle ";
  else 
    cout<<" no cycle";
  return 0;
}