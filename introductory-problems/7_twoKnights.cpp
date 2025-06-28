#include <iostream>
#define int long long
using namespace std;


int32_t main(){
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
        int total = (i * i) * (i * i - 1) / 2;
        int invalid = 2 * 2 * (i - 2) * (i - 1);
        cout << total - invalid << "\n";
    }
    return 0;
}