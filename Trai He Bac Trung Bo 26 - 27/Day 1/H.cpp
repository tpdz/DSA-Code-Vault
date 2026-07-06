#include<bits/stdc++.h>
#define ll long long
#define NAME "deggraph"
using namespace std;
const int N=1e5+5;
const ll INF=1e18;
int n,m,k;
vector<pair<int,int>>g[N];
ll dist[2][N];
void dijkstra(){
    for(int c=0;c<=k;++c){
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        int cur=c%2,nxt=(c+1)%2;
        for(int i=1;i<=n;++i)if(dist[cur][i]!=INF)pq.push({dist[cur][i],i});
        while(!pq.empty()){
            auto [a,b]=pq.top();pq.pop();
            if(dist[cur][b]!=a)continue;
            for(auto [v,w]:g[b]){
                if(dist[cur][v]>a+w){
                    dist[cur][v]=a+w;
                    pq.push({a+w,v});
                }
                if(c<k)dist[nxt][v]=min(dist[nxt][v],a-w);
            }
        }
        for(int i=1;i<=n;++i)dist[nxt][i]=min(dist[nxt][i],dist[cur][i]),dist[cur][i]=INF;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen(NAME".inp","r")){
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    for(int i=1;i<=n;++i)dist[0][i]=dist[1][i]=INF;
    dist[0][1]=0;
    dijkstra();
    cout<<min(dist[1][n],dist[0][n]);
    return 0;
}