#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define endl '\n'
#define br cout<<endl
#define mem(a) memset(a,0,sizeof(a))
const double pi=3.141592653589793238;
#define d(x) cout<<x<<endl;
#define de(x) cout<<#x<<" "<<x<<endl;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define rev(a) reverse(a.begin(),a.end())
const int inf = 100000000000000000;
#define maxn 1000005
int mod = (int)(1e9 + 7);
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
//#define f(i,n) for(int i=1;i<=n;i++)
#define fp(i,k,n) for(int i=k;i<=n;i+=1)
#define fn(i,k,n) for(int i=k;i>=n;i-=1)
void pv(vector<int> v){  for (int i = 0; i < v.size(); ++i){cout<<v[i]<<" ";}cout<<endl;}
void pa(int a[],int n,int p){for (int i = p; i < n+p; ++i){cout<<a[i]<<" ";}cout<<endl;}
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
// vector<int> edge[maxn];
// void ipgraph(int n,int m) {
//     fp(i,1,n) edge[i].clear();
//     if(m==0) return;
//    fp(i,1,m) {
//        int a,b;
//        cin>>a>>b;
//        edge[a].pb(b);
//        edge[b].pb(a);
//    } 
// }
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
//////////////////////////////////////////////////////////////////////////////////
int n,m;
vector<int> per;
std::vector<std::vector<int>> Permutations;
void permute(int l)  
{  
    // Base case  
    int r = n - 1;
    if (l == n)  
        Permutations.pb(per);  
    else
    {  
        // Permutations made  
        for (int i = l; i <= r; i++)  
        {  
  
            // Swapping done  
            swap(per[l], per[i]);  
  
            // Recursion called  
            permute(l+1);  
  
            //backtrack  
            swap(per[l], per[i]);  
        }  
    }  
}  
void solve()
{
    cin>>n>>m;
    int weight[n+1];
    fp(i,1,n) {cin>>weight[i];per.pb(i);}
    pair<int,int> v[m+1];
    fp(i,1,m)
    {
        cin>>v[i].S>>v[i].F;
    }
    sort(v+1,v+m+1);
    int prefix[m+2];
    prefix[0] = 0;
    fp(i,1,m) prefix[i] = max(prefix[i-1],v[i].S);
    prefix[m+1] = prefix[m];
    fp(i,1,n)
    {
        if(weight[i]>v[m].F)
        {
            d(-1)
            return ;
        }
    }
    int ans = inf;
    permute(0);
    for(auto p : Permutations)
    {
        int w[n+1];
        fp(i,1,n) w[i] = weight[p[i-1]];
        int dp[n+1][n+1];
        dp[1][1] = 0;
        fp(i,2,n)
        {
            int weightSum = w[i];
            dp[i][i] = 0;
            fn(j,i-1,1)
            {
                weightSum+=w[j];
                int id = lower_bound(v+1,v+m+1,mp(weightSum,0LL)) - v - 1;
                dp[j][i] = prefix[id];
                //d(j<<" "<<i<<" "<<dp[j][i])
                
            }
        }
        fp(i,1,n)
        {
            fn(j,i-1,1)
            {
                fp(k,j,i) dp[j][i] = max(dp[j][i],dp[j][k]+dp[k][i]);
            }
        }
        ans = min(ans,dp[1][n]);
    }
    if(ans==inf)
    {
        while(1) ;
    }
    else d(ans)
}   
int32_t main()
{
   IOS;
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif
    std::cout << std::setprecision(20);
   int t=1;
    //cin>>t;
   fp(i,1,t)
   {
       //cout<<"Case #"<<i<<": ";
       solve();
   }
}