#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int ans = 0;
    while(n){
        ans += n / 5;
        n = n / 5;
    }
    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}