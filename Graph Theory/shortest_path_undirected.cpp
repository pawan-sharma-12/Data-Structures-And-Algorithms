#include<bits/stdc++.h>
using namespace std;
void shortest_path(int src,vector<int> adj[],vector<int> &distance)
{
    int node = src;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        
        for(auto it :adj[node])
        {
            if(distance[node]+1 < distance[it]){
                distance[it] = distance[node]+1;
                q.push(it);
            }

        }
        q.pop();
    }
}
int main()
{
  int n, e,u,v,src;
  cin>>n>>e>>src;
  vector<int>  adj[e+1];
  for(int i =1;i<=e;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> distance(n+1,INT_MAX);
    distance[src] = 0;
    shortest_path(src,adj,distance);
    //printing the sortest path to nodes with respect to source
    cout<<"nodes :"<<endl;
     for(int i =1;i<distance.size();i++)
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
    
    cout<<"distances :"<<endl;
    for(int i =1;i<n+1;i++)
    {
        cout<<distance[i]<<" ";
    }
  return 0;
}