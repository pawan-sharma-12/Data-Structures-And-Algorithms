#include<bits/stdc++.h>
using namespace std;
int main()
{

  int n;
  cin>>n;
  string s;
  cin>>s;
   int c=0;
   int o=0;
  //sort(s.begin(),s.end());
   for(int i=0;i<n;i++)
   {
       if(s[i]=='1')
         c++;
         else
         o++;
   }
    n=o;
   
 string b;
 if(c==0)
 b.resize(n);
 else
  b.resize(n+1);
  b={};
   
for(int i=0;i<n+1;i++)
  {
     if((i==0)&&(c==0))
       {continue;}
     if((i==0)&&(c!=0))
       b.push_back('1');
       else
       b.push_back('0');
  }
cout<<b<<endl;

}