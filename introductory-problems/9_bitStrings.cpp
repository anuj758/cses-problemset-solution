#include <iostream>
#include <vector>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    int ans = 1;
    int a = 2;
    while(n){
        if(n & 1) ans *= a;
        n = n >> 1;
        a *= a;
        ans %= mod;
        a %= mod;
    }
    cout << ans << "\n";
}

int32_t main(){
    solve();
    return 0;
}