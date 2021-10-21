#include<bits/stdc++.h>
using namespace std;
 void Bfs(int n,vector<int> vec[],vector<int>& bfs)
{
  
    queue<int> q;
    vector<int> visited(n+1,0);
    for(int i = 1 ;i<=n;i++)
   {
      if(visited[i]==0)
      {
          queue<int> q;
          q.push(i);
          visited[i] = 1;
          while(!q.empty())
          {
              int node = q.front();
              q.pop();
                bfs.push_back(node);
                for(auto it:vec[node])
                {
                    if(visited[it]==0)
                    {
                        q.push(it);
                        visited[it] =1 ;
                    }
                }
          }
      }
   }

}
int main()
{
   int n,e,u,v;
   cin>>n>>e;
   vector<int> adj[n+1];
   vector<int>bfs;
   
    for(int i = 0   ;i<e;i++)
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
    //calling bfs function 
    Bfs(n,adj,bfs);
    //printing the bfs
    cout<<"BFS of the above graph is:"<<endl;
    for(int i = 0 ;i<n;i++)
      cout<<" "<<bfs[i];
  return 0;
}