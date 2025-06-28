#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> pA;
    if(a + b > n || (a > 0 && b == 0) || (a == 0 && b > 0)){
        cout << "NO" << "\n";
        return;
    }
    int draws = n - (a + b);
    int N = n - draws;
    for(int i = 1; i <= n; i++){
        if(i <= a) pA.push_back(b + i);
        else if(i <= N) pA.push_back(i - a);
        else pA.push_back(i);
    }
    cout << "YES" << "\n";
    for(int i = 0; i < n; i++){
        cout << pA[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << "\n";
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("0_input.txt", "r", stdin);
        freopen("0_output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}