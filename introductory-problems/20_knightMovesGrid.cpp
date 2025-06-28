#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n, -1));
    int delX[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int delY[] = {1, 2, 2, 1, -1, -2, -2, -1};
    queue<pair<int,int>> q;
    q.push({0, 0});
    grid[0][0] = 0;
    while(!q.empty()){
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int newRow = currRow + delX[i];
            int newCol = currCol + delY[i];
            if(newRow >= 0 && newRow < n && currCol >= 0 && currCol < n && grid[newRow][newCol] == -1){
                grid[newRow][newCol] = grid[currRow][currCol] + 1;
                q.push({newRow, newCol});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
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
    solve();
    return 0;
}