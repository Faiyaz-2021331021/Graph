///https://vjudge.net/contest/608541#problem/C

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
void solve()
{
    int n,m;cin>>n>>m;
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    vector<vector<pair<int, int>>> arr(n + 5);
    for(int i=0;i<m;i++)
    {
        int a,b,c;cin>>a>>b>>c;
        arr[a].pb({c,b});
        arr[b].pb({c,a});
    }
    int sn;cin>>sn;
    for(auto i:arr[sn])
    {
        //cout<<i.first<<":"<<i.second<<endl;
        pq.push({i.first,{i.second,sn}});
    }
    int ans=0;
    while(!pq.empty())
    {
        auto cnode = pq.top();
        pq.pop();
        vis[cnode.second.second]=1;
        int pnode = cnode.second.first;
        if(vis[pnode]==0)
        {
            vis[pnode]=1;
            ans+=cnode.first;
            for(auto i:arr[pnode])
            {
                if(vis[i.second]==0)
                {
                    pq.push({i.first,{i.second,pnode}});
                }
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    //edm();
    int t = 1;
    //cin>>t;
    for(int i=1;i<=t;i++)
    {
        ///cout<<"Case "<<i<<": ";
        solve();
    }
} 
