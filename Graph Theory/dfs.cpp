#include<bits/stdc++.h>
using namespace std;
void Dfs_rec(int node,vector<int> &vis,vector<int> adj[],vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;
    for(auto it:adj[node])
    {
      if(vis[it]==0)
      {
         Dfs_rec(it,vis,adj,dfs); 
      }
}
}
vector<int> DFS(int n,vector<int> adj[])
{    
    vector<int> dfs;
    vector<int> vis(n+1,0);
    for(int i = 1;i<=n;i++)
    {
      if(vis[i]==0)
      {
          Dfs_rec(i,vis,adj,dfs);
      }
    }
    return dfs;
}

int main()
{
  int n,e,u,v;
  cin>>n>>e;
  vector<int> adj[n+1];
  vector<int> dfs;
  memset(adj,0,sizeof(adj));
  for(int i =1 ;i<=n;i++ )
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
   //printing nodes and edges
      cout<<"nodes :"<<endl;
     for(int i =1;i<=n;i++)
    {
      cout<<i<<" ";
    }
    cout<<endl<<"edges :"<<endl;
    for(int i = 1;i<=n;i++)
    {
        int node = i;
        for(int it :adj[node])
         {
             cout<<node <<" -- "<<it<<" ";
         }
         cout<<endl;
    }
    cout<<endl;
    //calling function to compute dfs
  dfs = DFS(n,adj);
  //printing the dfs
  cout<<"printing the dfs: "<<endl;
  for(int i = 0  ;i<n;i++)
   cout<<" "<<dfs[i];
  return 0;
}