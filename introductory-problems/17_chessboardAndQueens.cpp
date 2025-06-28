#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<char>>& grid, int row, int col){
    for(int i = col - 1; i >= 0; i--){
        if(grid[row][i] == 'q') return false;
    }
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(grid[i][j] == 'q') return false;
    }
    for(int i = row + 1, j = col - 1; i < 8 && j >= 0; i++, j--){
        if(grid[i][j] == 'q') return false;
    }
    return true;
}

int count(vector<vector<char>>& grid, int col){
    if(col == 8){
        return 1;
    }
    int cnt = 0;
    for(int row = 0; row < 8; row++){
        if(grid[row][col] == '.' && check(grid, row, col)){
            grid[row][col] = 'q';
            cnt += count(grid, col + 1);
            grid[row][col] = '.';
        }
    }
    return cnt;
}

void solve(){
    vector<vector<char>> grid(8, vector<char>(8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> grid[i][j];
        }
    }
    cout << count(grid, 0) << '\n';
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("0_input.txt", "r", stdin);
        freopen("0_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}