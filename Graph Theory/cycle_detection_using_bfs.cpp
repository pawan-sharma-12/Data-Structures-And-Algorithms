#include<bits/stdc++.h>
using namespace std;
bool bfsCycle(int i,vector<int> adj[],vector<int> &visited)
{
    queue<pair<int,int>> q;
    q.push({i,-1});
    
        visited[i] =1;
        while(!q.empty())
        {
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          for(auto it :adj[node])
          {
              if(!visited[it])
             {
                 visited[it]= 1;
                 q.push({it,node});
             }
             else if(parent != it) return true;
               
          }
        }
  
    return false;
}
bool isCycle(int n,vector<int> adj[])
{ 
    vector<int > visited(n+1,0);

    for(int i = 1 ;i<=n;i++)
    {
      
      if(!visited[i])
      {
         if(bfsCycle(i,adj,visited)) return true;
        
      }
    }
   return false;
}
int main()
{

  int n , e,u,v;
  cin>>n>>e;
  vector<int> adj[n+1];
  for(int i = 1 ;i<=e;i++)
  {
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if(isCycle(n,adj))
   cout<<"There is a cycle ";
  else
    cout<<"no cycle ";

  return 0;
}