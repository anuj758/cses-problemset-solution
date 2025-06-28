#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

void solve(){
    int q;
    cin >> q;
    vector<long long> v(18, 0);
    long long pow10[18];
    pow10[0] = 1;
    for(int i = 1; i < 18; i++) pow10[i] = pow10[i-1] * 10;

    for(int i = 1; i < 18; i++){
        v[i] += v[i - 1] + 9 * pow10[i - 1] * i; 
    }
    while(q--){
        long long int k;
        cin >> k;
        for(long long int i = 1; i < 18; i++){
            if(v[i] >= k){
                k -= v[i - 1];
                long long num = pow10[i - 1] - 1;
                long long numbers = k / i;
                long long digit = k % i;
                num = num + numbers;
                if(digit == 0){
                    cout << (num % 10) << "\n";
                }
                else{
                    string s = to_string(num + 1);
                    cout << s[digit - 1] << "\n";
                }
                break;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("0_input.txt", "r", stdin);
        freopen("0_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}