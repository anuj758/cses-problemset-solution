#include <iostream>
#include <vector>
#include <functional>
using namespace std;

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < 7 && y < 7);
}

void solve() {
    string s;
    cin >> s;
    vector<vector<bool>> vis(7, vector<bool>(7, false));
    int dx[] = {0, 0, 1, -1};  // Directions: L, R, D, U
    int dy[] = {-1, 1, 0, 0};
    string direction = "LRDU";   // Matches dx/dy indices

    function<int(int, int, int)> dfs = [&](int row, int col, int index) {
        if (index == 48) 
            return (row == 6 && col == 0) ? 1 : 0;
        if (row == 6 && col == 0) 
            return 0;

        // Compute blocked status for neighbors
        bool blocked[4] = {true, true, true, true};
        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (isValid(nrow, ncol)) 
                blocked[i] = vis[nrow][ncol];
        }

        // Grid-splitting checks
        if (blocked[0] && blocked[1] && !blocked[2] && !blocked[3]) return 0;
        if (blocked[2] && blocked[3] && !blocked[0] && !blocked[1]) return 0;
        //diagonal checks
        if (row > 0 && col > 0 && vis[row-1][col] && vis[row][col-1] && !vis[row-1][col-1]) 
            return 0;
        if (row > 0 && col < 6 && vis[row-1][col] && vis[row][col+1] && !vis[row-1][col+1]) 
            return 0;
        if (row < 6 && col > 0 && vis[row+1][col] && vis[row][col-1] && !vis[row+1][col-1]) 
            return 0;
        if (row < 6 && col < 6 && vis[row+1][col] && vis[row][col+1] && !vis[row+1][col+1]) 
            return 0;

        vis[row][col] = true;
        int cnt = 0;

        if (s[index] == '?') {
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (isValid(nrow, ncol) && !vis[nrow][ncol]) 
                    cnt += dfs(nrow, ncol, index + 1);
            }
        } 
        else {
            for (int i = 0; i < 4; i++) {
                if (s[index] == direction[i]) {
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];
                    if (isValid(nrow, ncol) && !vis[nrow][ncol]) 
                        cnt += dfs(nrow, ncol, index + 1);
                    break;
                }
            }
        }

        vis[row][col] = false;
        return cnt;
    };

    cout << dfs(0, 0, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("0_input.txt", "r", stdin);
        freopen("0_output.txt", "w", stdout);
    #endif
    solve();
    return 0;
}
