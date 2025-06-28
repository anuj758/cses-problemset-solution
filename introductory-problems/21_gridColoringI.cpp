#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<string> ans(n, string(m, ' '));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(char c = 'A'; c <= 'D'; c++){
                if(c == grid[i][j] || (i - 1 >= 0 && c == ans[i - 1][j]) || (j - 1 >= 0 && c == ans[i][j - 1])) continue;
                else{
                    ans[i][j] = c;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
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