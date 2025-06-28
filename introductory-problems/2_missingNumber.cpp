#include<iostream>
#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    int missingNumber = n;
    int x;
    for(int i = 0; i < n-1; i++){
        cin >> x;
        missingNumber += x;
        missingNumber -= i + 1;
    }
    cout << missingNumber << "\n";
    return 0;
}
