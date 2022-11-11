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
  return (par[x]<0?x:par[x]=FIND(par[x]));
}
int merge(int x,int y)
{
  x= FIND(x);
  y=FIND(y);

  if(x==y){return 0;}
if(par[x]<par[y])
{
    swap(x,y);
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
//cin>>tes;
while(tes--)
{
   cin>>n>>m;
   vector<pair<ll,int>>c(n);
   for(int i=0;i<n;i++)
   {
    cin>>c[i].first;
    c[i].second=i;
   }
   if(n==1 && !m)
   {
       cout<<0<<endl;
       continue;
   }
   memset(par,-1,sizeof(par));
vector<vector<ll>>store;
sort(c.begin(),c.end());
int ind=c[0].second;
for(int i=1;i<n;i++)
{
    ll val= c[0].first;
    val+= c[i].first;
    store.push_back({val,ind,c[i].second});
}
for(int i=0;i<m;i++)
{
    ll x,y,w; cin>>x>>y>>w;
    --x; --y;
    store.push_back({w,x,y});
}
sort(store.begin(),store.end());
ll ans=store[0][0];
int ok=1;
int root=store[0][1];
merge(store[0][1],store[0][2]);
for(int i=1;i<store.size();i++)
{
   int x=store[i][1]; int y=store[i][2];
   if(merge(x,y))
   {
       ok++;
       ans+= store[i][0];
   }
}


cout<<ans<<endl;

}
return 0; 
}   
// thinks of patterns in 0101 1010 ABABA
// look for 0,1,2 as only solutions
// don't get stuck with binary search
// spend more time
// consider n=0,n=1 in cases 