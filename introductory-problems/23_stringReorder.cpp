#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(int count[]){
    int maxOccur = 0;
    int total = 0;
    for(int i = 0; i < 26; i++){
        maxOccur = max(maxOccur, count[i]);
        total += count[i]; 
    }
    return maxOccur <= (total + 1) / 2;
}

void solve(){
    string s;
    cin >> s;
    int count[26] = {0};
    for(char c : s){
        count[c - 'A']++;
    }
    string answer;
    int lastChar = -1;
    for(int i = 0; i < int(s.size()); i++){
        bool fill = false;
        for(int c = 0; c < 26; c++){
            if(count[c] > 0 && lastChar != c){
                count[c]--;
                if(possible(count)){
                    answer.push_back(c + 'A');
                    fill = true;
                    lastChar = c;
                    break;
                }
                else count[c]++;
            }
        }
        if(fill == false) {
            cout << -1 << "\n";
            return ;
        }
    }
    cout << answer << "\n";  
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("0_input.txt", "r", stdin);
        freopen("0_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}