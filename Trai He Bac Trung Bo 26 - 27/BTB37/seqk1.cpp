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

ll n, k, t;

bool check(int val){
    int pre = 0, cnt = 0;
    while(val){
        if((val&1) != pre && (val&1)) ++cnt;
        pre = (val&1);
        val >>= 1;
    }
    return (cnt == k);
}

void Print(int mask){
    FORD(i, n-1, 0) cout<<GET_BIT(mask, i);
    cout<<'\n';
}

void sub1(){
    int ans = 0, cnt = 0;
    FOR(mask, 0, MASK(n)-1){
        if(check(mask)){
            ++cnt;
            if(cnt == t) ans = mask;
        }
    }

    //
    cout<<cnt<<'\n';
    Print(ans);
}

ll dp[130][130], p[130][130];

ll dem_xau(){

    memset(dp, 0, sizeof dp);
    memset(p, 0, sizeof p);

    if(!k){
        return 1;
    }

    FOR(i, 1, n){
        dp[i][1] = i;
        p[i][1] = p[i-1][1]+dp[i][1];
    }
    FOR(i, 0, n) p[i][0] = 1;

    FOR(i, 1, n)
    FOR(d, 2, k){
        FORD(j, i, 1){
            if(j < 3) dp[i][d] += p[0][d-1];
            else dp[i][d] += p[j-2][d-1];
        }
        p[i][d] = p[i-1][d] + dp[i][d];
    }

    return p[n][k];
}

int num, ansmask[130];

void Print1(){
    FORD(i, n, 1) cout<<ansmask[i];
    cout<<'\n';
}

void sinh(int i, int rem){

    if(i < 1){
        ++num;
        if(num == t){
            Print1();
            exit(0);
        }
        return;
    }

    FOR(d, 0, n){
        if(!d && p[i-1][rem]){
            ansmask[i] = 0;
            sinh(i-1, rem);
        }

        if(rem && i-d-1 >= -1 && d && p[max(0, i-d-1)][rem-1]){
            FORD(idx, i, i-d+1) ansmask[idx] = 1;
            ansmask[i-d] = 0;
            sinh(i-d-1, rem-1);
        }
    }

}

int main(){
    ngtphuoc
    //AC_AC_AC("seqk1")

    cin>>n>>k>>t;

    if(!k){
        cout<<1<<'\n';
        FOR(i, 1, n) cout<<0;
        return 0;
    }

    if(n <= 20){
        sub1();
        return 0;
    }

    if(n <= 60){
        cout<<dem_xau()<<'\n';
        sinh(n, k);
        return 0;
    }

    if(n <= 120){
        cout<<dem_xau()<<'\n';
        sinh(n, k);
        return 0;
    }

}