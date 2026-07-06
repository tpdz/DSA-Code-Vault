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

const int N = 1004;
int n, m, a[N][N], maxai, is[N][N], dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

namespace sub1{
    bool check() {return m == 1;}
    void solve(){
        int ma = 0, mi = INT_MAX;
        FOR(i, 1, n){
            ma = max(ma, a[i][1]);
            mi = min(mi, a[i][1]);
        }
        cout<<ma-mi;
        exit(0);
    }
}

namespace sub235{
    bool check() {return maxai <= 200;}

    bool bfs(int l, int r){
        if(a[1][1] < l || a[1][1] > r) return 0;

        queue<pair<int, int>> q;
        q.push({1, 1}); is[1][1] = 1;

        while(!q.empty()){
            int u = q.front().first, v = q.front().second;
            q.pop();

            FOR(k, 0, 3){
                int u1 = u+dx[k], v1 = v+dy[k];
                if(u1 < 1 || v1 < 1 || u1 > n || v1 > m || a[u1][v1] < l || a[u1][v1] > r) continue;
                if(!is[u1][v1]){
                    is[u1][v1] = 1;
                    q.push({u1, v1});
                }
            }
        }
        
        return is[n][m];
    }

    bool checkm(int x){
        FOR(l, 0, maxai-x){
            memset(is, 0, sizeof is);
            if(bfs(l, l+x)) return 1;
        }
        return 0;
    }

    void solve(){
        int l = 0, r = maxai, mid, ans;

        while(l <= r){
            mid = (l+r)>>1;
            if(checkm(mid)) r = mid-1, ans = mid;
            else l = mid+1;
        }
        cout<<ans;
        exit(0);
    }
}

namespace sub4{
    void solve(){

        exit(0);
    }
}

int main(){
    ngtphuoc
    AC_AC_AC("electric")

    cin>>n>>m;
    FOR(i, 1, n) FOR(j, 1, m) cin>>a[i][j], maxai = max(maxai, a[i][j]);

    if(sub1::check()) sub1::solve();
    if(sub235::check()) sub235::solve();
    sub4::solve();
}









