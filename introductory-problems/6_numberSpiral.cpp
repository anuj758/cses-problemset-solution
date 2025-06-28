#include <iostream>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        long long mx = max(x, y);
        long long answer = (mx - 1) * (mx - 1) + mx;
        if(mx & 1){  // mx -> odd
            if(x <= y){     //row is below mx
                answer += (mx - x); 
            }
            else{   // column is below mx
                answer -= (mx - y);
            }
        }
        else{
            if(x <= y){
                answer -= (mx - x); 
            }
            else{
                answer += (mx - y);
            }
        }
        cout << answer << "\n";
    }
    return 0;
}