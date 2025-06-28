#include <iostream>
using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;
    int b = (2 * y - x) / 3;
    int a = y - 2 * b;
    if(a >= 0 and b >= 0 and x == 2 * a + b and y == 2 * b + a) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}