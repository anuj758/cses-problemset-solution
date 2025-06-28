#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if((n * (n + 1)) % 4) {
        cout << "NO" << "\n";
        return;
    }
    vector <int> s1, s2;
    while(n>=4){
        s1.push_back(n);
        s1.push_back(n - 3);
        s2.push_back(n - 1);
        s2.push_back(n - 2);
        n -= 4;
    }
    if(n == 3){
        s1.push_back(3);
        s2.push_back(2);
        s2.push_back(1);
    }
    cout << "YES" << "\n";
    cout << s1.size() << "\n";
    for(auto x : s1) cout << x << " ";
    cout << "\n";
    cout << s2.size() << "\n";
    for(auto y : s2) cout << y << " ";
    cout << "\n";

}
int main(){
    solve();
    return 0;
}