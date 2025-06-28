#include <iostream>
#include <climits>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector <int> weight(n);
    long long int totalWeight = 0;
    for(int i = 0; i < n; i++){
        cin >> weight[i];
        totalWeight += weight[i]; 
    }
    long long int diff = INT_MAX;
    for(int i = 0; i < (1 << n); i++){
        long long weightTaken = 0;
        for(int bit = 0; bit < n; bit++){
            if(i & (1 << bit)) weightTaken += weight[bit];
        }
        diff = min(diff, abs(totalWeight - 2 * weightTaken));
    }
    cout << diff << "\n";
    return 0;
}