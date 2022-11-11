#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
const long long mod = 1e9+7;
//const long long mod =1000000007;
//const long long mod = 998244353;
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
ll dp[4];
int check=0;
int main()
{
init_code();
cout<<setprecision(12)<<fixed;
int tes=1;
//cin>>tes;
while(tes--)
{
cin>>n;   
string s; cin>>s;
dp[0]=1;
///1 string rn
for(int i=0;i<n;i++)
{
    if(s[i]=='a')
    {
        dp[1]+= dp[0];
        // if 3 strings, add a 3 times
    }else if(s[i]=='b')
    {
        dp[2]+= dp[1];
        // now number of ab's= number of a's+ prev(ab)
    }else if(s[i]=='c')
    {
        dp[3]+= dp[2];
    }else
    {
        dp[3]*=3;
        // if currently i had 1 string, now 3 options-> 3 strings
        dp[3]+= dp[2];
        // this one is C
        dp[2]*=3;
        dp[2]+=dp[1];
        // this one is b
        dp[1]*=3;
        dp[1]+=dp[0];
        dp[0]*=3;
        dp[0]%=mod;
        dp[1]%=mod;
        dp[2]%=mod;
        dp[3]%=mod;


    }
       dp[0]%=mod;
        dp[1]%=mod;
        dp[2]%=mod;
        dp[3]%=mod;
}
cout<<dp[3]%mod<<endl;


}
return 0; 
}   
// thinks of patterns in 0101 1010 ABABA
// look for 0,1,2 as only solutions
// don't get stuck with binary search
// spend more time
// consider n=0,n=1 in cases 