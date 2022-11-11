#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//const long long mod = 1e9+7;
//const long long mod =1000000007;
const long long mod = 998244353;
const long long int special_prime = 982451653;
using namespace std;
#define ll long long int
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define Min(a, b) ((a < b) ? a : b)
#define Max(a, b) ((a < b) ? b : a)

void init_code()
{
FAST;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
#endif

}
const int rn= 3e5+5;
const int MX=2000001;
const int nx=20;
int n,m,k;
vector<int>adj[MX];
int timer=0;
int a[MX],b[MX],d[MX];
//int vis[MX],dp[MX];
int par[MX];
int check=0;
int FIND(int x)
{
  return (par[x]<0?x:par[x]=FIND(x));
}
int merge(int x,int y)
{
  x= FIND(x);
  y=FIND(y);

  if(x==y){return 0;}
if(par[x]<par[y])
{
    swap(par[x],par[y]);
}
par[x]+= par[y];
par[y]=x;
return 1;

}


int main()
{
init_code();
cout<<setprecision(12)<<fixed;
int tes=1;
cin>>tes;
while(tes--)
{
    cin>>n;
    int bit[31]={0};
    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        for(int j=0;j<=30;j++)
        {
            if(x&(1<<j))
            {
                bit[j]++;
            }
        }
    }
    check=0;
for(int i=30;i>=0;i--)
{
    int cn=bit[i];
    if(cn%2==0)
    {
        continue;
    }
//now if the count is 3? or 1 
    check=1;
if(cn%4==1)
{
    cout<<"WIN"<<endl; break;
}else if(cn%4==3)
{
    if(n%2==0)
        {cout<<"WIN"<<endl; break;}
    else{cout<<"LOSE"<<endl;
    break;
    }
}
}
if(check){continue;}
cout<<"DRAW"<<endl;



}
return 0; 
}   
// thinks of patterns in 0101 1010 ABABA
// look for 0,1,2 as only solutions
// don't get stuck with binary search
// spend more time
// consider n=0,n=1 in cases 