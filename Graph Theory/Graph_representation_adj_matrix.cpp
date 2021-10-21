#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n ,e;
  cin>>n>>e;
  int u, v;
  int adj[n+1][n+1];
  memset(adj,0,sizeof(adj));
  for(int i = 0 ;i<e;i++)
  {
     cin>>u>>v;
     adj[u][v] = 1;
     adj[v][u] = 1; 
  }
  
  for(int i  = 0 ;i<n+1;i++)
  {
      for(int j =0 ;j<n+1;j++)
      {
          cout<<"  "<<adj[i][j];
      }
      cout<<endl;
  }
  return 0;
}   