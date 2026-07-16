#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define GET_BIT(x, i) (((x) >> (i)) & (1))
#define MASK(i) ((1LL) << (i))
#define ON_BIT(x, i) ((x) | MASK(i))
#define OFF_BIT(x, i) ((x) & ~MASK(i))
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define ngtphuoc ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define AC_AC_AC(filename) freopen(filename".inp","r",stdin); freopen(filename".out","w",stdout);

const int N = 1e5+5;
ll rmq[N][20], n, q, k, a[N], pos[N];
vector<int> pos1[N];

//
ll get_gcd(int l, int r){
    int l1 = __lg(r-l+1);
    return __gcd(rmq[l][l1], rmq[r-(1<<l1)+1][l1]);
}
void init(){
    for(int l1 = 1; (1 << l1) <= n; ++l1){
        FOR(i, 1, n-(1 << l1)+1){
            rmq[i][l1] = __gcd(rmq[i][l1-1], rmq[i+(1<<(l1-1))][l1-1]);
        }
    }

    int j = 1;
    FOR(i, 1, n){
        while(j <= i && get_gcd(j, i) <= k) ++j;
        pos[i] = j-1;
        pos1[pos[i]].push_back(i);
    }
}

//
struct Queries{
    int l, r, id;
};
bool cmp(Queries x, Queries y){
    return x.l < y.l;
}
Queries qu[N];
ll ans[N];

//
ll bit[N], bitc[N];
void upt(int i, ll val){
    for(; i <= n; i += i&-i){
        bit[i] += val;
        ++bitc[i];
    }
}
pair<ll, ll> query(int i){
    if(!i) return {0, 0};
    ll sum = 0, cnt = 0;
    for(; i; i -= i&-i){
        sum += bit[i];
        cnt += bitc[i];
    }
    return {sum, cnt};
}
pair<ll, ll> get_sum(int l, int r){
    pair<ll, ll> L = query(l-1);
    pair<ll, ll> R = query(r);
    return {R.first-L.first, R.second-L.second};
}

//
void offline(){
    int j = n;

    FORD(i, q, 1){
        int L = qu[i].l, R = qu[i].r;
        while(j >= L){
            for(int p : pos1[j]){
                upt(p, j);
            }
            --j;
        }
        pair<ll, ll> G = get_sum(L, R);
        ll sum = G.first, cnt = G.second;
        ans[qu[i].id] = sum-cnt*L+cnt;
    }
}

int main(){
    ngtphuoc
    //AC_AC_AC("gcdseq")

    cin>>n>>q>>k;
    FOR(i, 1, n){
        cin>>a[i];
        rmq[i][0] = a[i];
    }
    init();

    //
    FOR(i, 1, q){
        cin>>qu[i].l>>qu[i].r;
        qu[i].id = i;
    }
    sort(qu+1, qu+1+q, cmp);
    offline();
    FOR(i, 1, q) cout<<ans[i]<<'\n';

}








