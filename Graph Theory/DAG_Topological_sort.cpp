#include<bits/stdc++.h>
using namespace std;
void print(vector<int> v,int n)
{
    for(int i =0 ;i<n;i++)
     cout<<" "<<v[i];
}
void dfsTopo(int node, vector<int> adj[],vector<int> &visited,stack<int> &st)
{
    visited[node] =1 ;
    for(int it : adj[node])
    {
        if(!visited[it])
        dfsTopo(it,adj,visited,st);
    }
    st.push(node);
}
void TopoSort(int n,vector<int> adj[],vector<int> &topoAns)
{
    vector<int> visited(n+1,0);
    stack<int> st;
     for(int i = 1 ;i<=n;i++)
     {
          if(!visited[i])
          {
              dfsTopo(i, adj,visited,st);
          }
     }
     
     while(!st.empty())
     {
         topoAns.push_back(st.top());
        st.pop();
     }
}
int main()
{
  int n , e,u,v;
  cin>>n>>e;
  vector<int> adj[n+1];
  vector<int> topoAns;
  for(int i = 1 ;i<=e;i++)
  {
      cin>>u>>v;
      adj[u].push_back(v);
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
             cout<<node <<" --> "<<it<<" ";
         }
         cout<<endl;
    }
    cout<<endl;
    //calling the function for computing the dfs
  TopoSort(n,adj,topoAns);
  //printing the dfs
  cout<<" dfs :"<<endl;
  print(topoAns,n);
  return 0;
}