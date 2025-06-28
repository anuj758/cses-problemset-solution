#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve(){
    string str;
    cin >> str;
    vector <int> v(26, 0);
    string ans;
    for(char c : str){
        v[c - 'A']++;
        if(v[c - 'A'] >= 2){
            ans.push_back(c);
            v[c - 'A'] -= 2; 
        }
    }
    int index = INT_MAX;
    for(int i = 0; i < 26; i++){
        if(v[i] == 1){
            index = i;
            break;
        }
    }
    int start = ans.size() - 1;
    if(index != INT_MAX)  ans.push_back(index + 'A');
    while(start >= 0)   ans.push_back(ans[start--]);
    if(ans.size() == str.size()) cout << ans << "\n";
    else cout << "NO SOLUTION" << "\n";
    
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}