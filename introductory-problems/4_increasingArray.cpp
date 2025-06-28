#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int curr;
    int prev = 0;
    long long ops = 0;
    for(int i = 0; i < n; i++){
        cin >> curr;
        if(prev > curr){
            ops += prev - curr;
            curr = prev;
        }
        prev = curr;
    }
    cout << ops << "\n";
    return 0;
}