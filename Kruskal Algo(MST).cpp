///https://vjudge.net/contest/608541#problem/B


#include<bits/stdc++.h>
using namespace std;
#define int            long long
#define pb             push_back
#define el             '\n'
#define pp             pair<int,pair<int,int>>
#define asort(a,n)     sort(a,a+n) 
#define vsort(v)       sort(v.begin(),v.end())
#define vrsort(v)      sort(v.rbegin(),v.rend());
const int N = 999999;
vector<pair<int,int>>arr[N];
int vis[N];
int par[N];
stack<int>ans,rem;
void edm()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}
int findpar(int n)
{
    if(par[n]==n)return n;
    else return par[n] = findpar(par[n]);
}
bool connected(int u,int v)
{
    if(findpar(u)==findpar(v))return true;
    else return false;
}
void match(int u,int v)
{
    u = findpar(u);
    v = findpar(v);
    if(u!=v)par[v]=u;
}
void dfs(int m,int par,int n)
{
    if(m==n)
    {
        ans = rem;
        return; 
    }
    if(vis[m]==1)return;

    vis[m]=1;
    rem.push(m);
    for(auto it:arr[m])
    {
        int nd = it.first;
        if(nd!=par)
        {
            dfs(nd,m,n);
        }
    }
    rem.pop();
}
void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n+1;i++)
    {
        vis[i]=0;
        par[i]=i;
        arr[i].clear();
    }
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    while(m--)
    {
        int a,b,c;cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    int ans=0;
    while(!pq.empty())
    {
        auto cnode = pq.top();
        pq.pop();
        if(!connected(cnode.second.first,cnode.second.second))
        {
            match(cnode.second.first,cnode.second.second);
            ans+=cnode.first;
        }
    }
    cout<<ans<<el;
}
signed main()
{
    edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<"Case "<<i<<": ";
        solve();
    }
} 
