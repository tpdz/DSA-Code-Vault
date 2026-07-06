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

int n;
ll mask[26], ans, target;

int main(){
    ngtphuoc
    AC_AC_AC("pangram")

    cin>>n;
    FOR(i, 0, n-1){
        string s; cin>>s;
        for(char c : s) mask[i] = ON_BIT(mask[i], c-'a');
    }

    target = MASK(26)-1;

    FOR(i, 1, MASK(n)-1){
        ll cur = 0;
        FOR(j, 0, n-1) if(GET_BIT(i, j)) cur |= mask[j];
        if(cur == target) ++ans;
    }

    cout<<ans;
}
