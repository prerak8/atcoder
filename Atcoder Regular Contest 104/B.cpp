#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
#define br cout<<endl
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 1000005
#define mod 998244353
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define f(i,n) for(int i=1;i<=n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i+=1)
#define fn(i,k,n) for(int i=k;i>=n;i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
int modexp(int x,int y) {
   int res = 1;
   x = x % mod;
   while (y > 0){
       if (y & 1LL)
           res = (res*x) % mod;
       y = y>>1;
       x = (x*x) % mod;  
   }
   return res;
}
int invmod(int a) {
    return modexp(a,mod-2);
}
vector<int> edge[maxn];
void ipgraph(int n,int m) {
    fp(i,1,n) edge[i].clear();
    if(m==0) return;
   fp(i,1,m) {
       int a,b;
       cin>>a>>b;
       edge[a].pb(b);
       edge[b].pb(a);
   } 
}
/*
void dfs(int node,int p)
{
    for(int u : edge[node]) 
    {
        if(u!=p)
        {
            dfs(u,node);
        }
    }
}
*/
///////////////////////////////////////////////////////////////////////////////////
void solve()
{
    int n;
    cin>>n;
    int pre[n+1],pre1[n+1];
    pre[0] = pre1[0] = 0;
    string s;
    cin>>s;
    s = " " + s;
    fp(i,1,n)
    {
        pre[i] = pre[i-1];
        pre1[i] = pre1[i-1];
        if(s[i]=='A') pre[i]++;
        else if(s[i]=='T') pre[i]--;
        else if(s[i]=='C') pre1[i]++;
        else if(s[i]=='G') pre1[i]--;
    }
    int ans = 0;
    fp(i,1,n)
    {
        fp(j,i,n)
        {
            if(pre[j]==pre[i-1] && pre1[j]==pre1[i-1]) ans++;
        }
    }
    d(ans)
}
int32_t main()
{
   IOS;
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
   int t=1;
    //cin>>t;
   fp(i,1,t)
   {
       //cout<<"Case #"<<i<<": ";
       solve();
   }
   #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
}