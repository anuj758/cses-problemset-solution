#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    //base cases
    if( n == 2 || n == 3){
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
    // write all even number and then followed by odd numbers
    for(int i = 2; i <= n; i += 2){
        cout << i << " ";
    }
    for(int i = 1; i <= n; i +=2){
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}