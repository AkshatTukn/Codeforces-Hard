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
int n,m,k;
vector<int>adj[MX];
int a[MX],b[MX],c[MX];
//int vis[MX],dp[MX];
int check=0;
template<typename int_t>
struct sparsemx{
 const int LG=20;
 vector<vector<int_t>>st;
 vector<int>sp2;
   
   void init(int n, int_t* a)
   {
      sp2= vector<int>(n+1);
      st= vector<vector<int_t>>(n+1,vector<int_t>(LG+1));
      int r=0;
  
  for(int i=1;i<=n;i++)
  {
    while(2*(1<<r) <= i)
    {
        r++;
    }
    sp2[i]=r;
  }

  for(int i=0;i<n;i++)
  {
        st[i][0]=a[i];
  }

for(int i=1;i<LG;i++)
{
    for(int j=0;j<n;j++)
    {
        if(j+(1<<(i-1))>=n){break;}
        st[j][i]=Max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    }
}

   }
int_t query(int l,int r)
{
    int x=sp2[r-l+1];
    return Max(st[l][x],st[r-(1<<x)+1][x]);
}
};
template<typename int_t>
struct sparsemn {
    const int LG = 20;
    vector<vector<int_t>> st;
    vector<int> sp2;
    
    void init(int n, int_t* a) {
        st = vector<vector<int_t>>(LG, vector<int_t>(n));
        sp2 = vector<int>(n + 1);
        
        for (int i = 0; i < n; i++) st[0][i] = a[i];
        
        int r = 0;
        for (int i = 1; i <= n; i++) {
            while (2 * (1 << r) <= i) ++r;
            sp2[i] = r;
        }
        
        for (int j = 1; j < LG; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << j) - 1 >= n) break;
                
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]); // combine
            }
        }
    }
    
    int_t query(int l, int r) {
        int x = sp2[r - l + 1];
        
        return min(st[x][l], st[x][r - (1 << x) + 1]);
    }
};

sparsemx<int>maxi;
sparsemn<int>mini;
int solve(int l,int r)
{
 if(r<=l){return 0;}
 int inda= maxi.query(l,r);
 int indb= mini.query(l,r);
 int ind1= b[inda];
 int ind2= b[indb];
 if(ind1>ind2)
 {
      swap(ind1,ind2);
 }
int ans=1+solve(l,ind1)+solve(ind2,r);
return ans;
}


int main()
{
init_code();
cout<<setprecision(12)<<fixed;
int tes=1;
cin>>tes;
while(tes--)
{
   // edge if index broo
   // 1,2,3,4,5
   // cant actually make the graph
    cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    a[i]--;
    b[a[i]]=i;
  }
mini.init(n,a);
maxi.init(n,a);
int ans=solve(0,n-1);
cout<<ans<<endl;
}
return 0; 
}   
// thinks of patterns in 0101 1010 ABABA
// look for 0,1,2 as only solutions
// don't get stuck with binary search
// spend more time
// consider n=0,n=1 in cases 