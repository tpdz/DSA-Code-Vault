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
int n, q, a[3][N];

pair<int, int> pos[2*N];

struct mov{
    int r1, c1, r2, c2;
};

vector<mov> ans;

void sort1(int r){
    FOR(i, 1, n) FOR(c, 2, n){
        if(a[r][c] <= a[r][c-1]){
            swap(a[r][c], a[r][c-1]);
            ans.push_back({r, c-1, r, c});
        }
    }
}

void swap1(int r, int c, int r1, int c1){
    if(c1 >= c) ans.push_back({r, c, 1, c1});
    else ans.push_back({1, c1, r, c});

    ans.push_back({r, c1, r1, c1});

    if(c1 >= c) ans.push_back({r, c, 1, c1});
    else ans.push_back({1, c1, r, c});
    swap(a[r][c], a[r1][c1]);
}

void sub12(){

    vector<int> wro;
    FOR(c, 1, n) if(a[2][c] <= n) wro.push_back(c);

    FOR(c, 1, n) if(a[1][c] > n){
        swap1(1, c, 2, wro.back());
        wro.pop_back();
    }

    sort1(1);
    sort1(2);

    cout<<ans.size()<<'\n';
    for(mov i : ans){
        cout<<i.r1<<' '<<i.c1<<' '<<i.r2<<' '<<i.c2<<'\n';
    }

    // FOR(i, 1, 2){
    //     FOR(j, 1, n) cout<<a[i][j]<<' ';
    //     cout<<'\n';
    // }
}

int main(){
    ngtphuoc
    //AC_AC_AC("grid")


    cin>>n>>q;
    FOR(i, 1, 2) FOR(j, 1, n){
        cin>>a[i][j];
        pos[a[i][j]] = {i, j};
    }

    sub12();
}





