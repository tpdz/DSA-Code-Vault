#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= (_b); ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= (_b); --i)
#define MASK(i) ((1LL) << (i))
#define GET_BIT(x, i) (((x) >> (i)) & (1))
#define ON_BIT(x, i) ((x) | MASK(i))
#define OFF_BIT(x, i) ((x) & ~MASK(i))
#define ngtphuoc ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define AC_AC_AC(filename) freopen(filename".inp", "r", stdin); freopen(filename".out", "w", stdout);

const int N = 2e5+5;

struct edge{
    int u, v;
    ll w;

    bool operator < (const edge& o) const{
        return w < o.w;
    }

};

struct DSU{
    vector<int> sz, par;
    DSU(int n){
        sz.assign(n+5, 1);
        par.resize(n+5);
        FOR(i, 0, n) par[i] = i;
    }

    int find(int u){
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }

    bool same(int u, int v){
        return (find(u) == find(v));
    }
};

edge a[N];

int main(){
    ngtphuoc
    //AC_AC_AC();

    int n, m;
    cin>>n>>m;
    DSU d(n);

    FOR(i, 1, m) cin>>a[i].u>>a[i].v>>a[i].w;

    sort(a+1, a+1+m);

    ll ans = 0, cnt = 0;

    FOR(i, 1, m){
        if(!d.same(a[i].u, a[i].v)){
            ans += a[i].w;
            d.unite(a[i].u, a[i].v);
            cnt++;
        }
    }

    (cnt != n-1 ? cout<<"IMPOSSIBLE" : cout<<ans);

}