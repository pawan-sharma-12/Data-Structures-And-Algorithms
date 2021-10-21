#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,e;
  cin>>n>>e;
  vector<pair<int,int>> adj[n+1];
  int u,v,wt;
  for(int i = 0;i<n+1;i++)
  {
      adj[u].push_back({v,wt});
      adj[v].push_back({u,wt});  
  }
   
  return 0;
}   
}