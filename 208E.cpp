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
const int MX=200001;
const int nx=20;
int n,m,k;
vector<int>adj[MX];
int table[MX][nx+1];
vector<int>store[MX];
vector<int>tin,tout,d;
int timer=0;
//int vis[MX],dp[MX];
int check=0;
void dfs(int x,int par,int dep)
{
 tin[x]=++timer;
 //timer++;
  table[x][0]=par;
  d[x]=dep;
  store[dep].push_back(timer);
  for(int k:adj[x])
  {
    if(k!=par)
    {
        dfs(k,x,dep+1);
    }
  }
tout[x]=++timer;
}

int kth(int x,int k)
{
    int ans=x;
    for(int i=20;i>=0;i--)
    {
        if(k&(1<<i))
        {
            ans=table[ans][i];
        }
    }
return ans;

}


int main()
{
init_code();
cout<<setprecision(12)<<fixed;
int tes=1;
//cin>>tes;
while(tes--)
{
   cin>>n;
   tin=vector<int>(n+1,0);
   tout=vector<int>(n+1,0);
   d=vector<int>(n+1,0);
   for(int i=0;i<n;i++)
   {
    int x; cin>>x;
    adj[x].push_back(i+1);
   }
dfs(0,0,0);
for(int j=1;j<=20;j++)
{

    for(int i=1;i<=n;i++)
    {
        table[i][j]=table[table[i][j-1]][j-1];
    }
}
int q; cin>>q;
while(q--)
{
    int x,k; cin>>x>>k;
    ll cur=kth(x,k);
    if(cur==0)
    {
        cout<<0<<" ";
    }else
    {
         int need= d[x];
         int ans= upper_bound(store[need].begin(),store[need].end(),tout[cur])-lower_bound(store[need].begin(),store[need].end(),tin[cur]);
         ans--;
         cout<<ans<<" ";

    }
}






}
return 0; 
}   
// thinks of patterns in 0101 1010 ABABA
// look for 0,1,2 as only solutions
// don't get stuck with binary search
// spend more time
// consider n=0,n=1 in cases 