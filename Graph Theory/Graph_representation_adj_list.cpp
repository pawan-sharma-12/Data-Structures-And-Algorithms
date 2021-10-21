#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,e;
  cin>>n>>e;
  vector<int> adj[n+1];
  int u,v;
  for(int i = 0;i<n+1;i++)
  {
      adj[u].push_back(v);
      adj[v].push_back(u);  
  }
    for(int i  = 0 ;i<n+1;i++)
  {
      for(int j =0 ;j<n+1;j++)
      {
          cout<<"  "<<adj[i][j];
      }
      cout<<endl;
  return 0;
}   
}