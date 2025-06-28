#include <iostream>
#include <vector>
using namespace std;

// mathematical approach
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (i ^ j) << " ";
        }
        cout << "\n";
    }
}

// practical approach or brute force
void solve2(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vector<bool> seen(2 * n, false);
            for(int k = 0; k < j; k++){  // for row
                seen[grid[i][k]] = true;
            } 
            for(int k = 0; k < i; k++){ // for column
                seen[grid[k][j]] = true;
            }

            for(int k = 0; k < 2 * n; k++){ 
                if(seen[k] == false){
                    grid[i][j] = k;
                    break;
                }
            }
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("0_input.txt", "r", stdin);
        freopen("0_output.txt", "w", stdout);
    #endif

    solve2();

    return 0;
}