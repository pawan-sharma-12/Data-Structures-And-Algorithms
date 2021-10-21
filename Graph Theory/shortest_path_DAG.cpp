#include<bits/stdc++.h>
using namespace std;
void dfs_topo(int i ,vector<pair<int,int>> adj[],vector<int> &visited,stack<int> &st)
{
    int node = i;
    visited[node]=1;
    for(auto it: adj[node])
    {
        if(!visited[it.first])
        {
            dfs_topo(it.first,adj,visited,st);
        }
    }
    st.push(node);
}
void Topo(int n,vector<pair<int,int>> adj[],stack<int> &st)
{
    vector<int> visited(n+1,0);
    
    for(int i = 1 ;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs_topo(i,adj,visited,st);
        }
    }
}
void shortest_path(int n,vector<pair<int,int>> adj[],vector<int> &distance)
{
    stack<int> st;
    Topo(n,adj,st);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if(distance[node]!= INT_MAX)
        {
             for(auto it : adj[node])
            {
                if(distance[it.first] > distance[node]+it.second){
                    distance[it.first] = distance[node]+it.second  ;  
                }
            }
        }
    }
    
}
int main()
{
  int n,e,u,v,wt,src;
  cin>>n>>e>>src;
  vector<pair<int,int>> adj[n*n];
  for(int i = 1;i<=e;i++)
  {
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});
  }
    vector<int> distance(n+1,INT_MAX);
    distance[src] =0;
    shortest_path(n,adj,distance);
      //printing the sortest path to nodes with respect to source
    cout<<"nodes :"<<endl;
     for(int i =1;i<distance.size();i++)
    {
      cout<<i<<" ";
    }
    cout<<endl;
    cout<<"distances :"<<endl;
    for(int i =1;i<distance.size();i++)
    {
        cout<<distance[i]<<" ";
    }
  return 0;
}