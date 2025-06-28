#include <iostream>
#include <vector>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector <string> v = {"0","1"};
    for(int i = 2; i <= n; i++){
        vector <string> temp;
        for(int j = 0; j < v.size(); j++){
            if(j & 1){
                temp.push_back(v[j] + "0");
                temp.push_back(v[j] + "1");
            }
            else{
                temp.push_back(v[j] + "1");
                temp.push_back(v[j] + "0");                
            }
        }
        v = temp;
    }
    for(string s: v) cout << s << "\n"; 
    return 0;
}