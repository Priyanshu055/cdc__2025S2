#include <bits/stdc++.h>
using namespace std;

int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> dirX = {-1, 0, 1, 0};
    vector<int> dirY = {0, 1, 0, -1};

    // DFS to mark boundary-connected lands
    function<void(int, int)> dfs = [&](int x, int y) {
        visited[x][y] = true;
        for (int d = 0; d < 4; d++) {
            int newX = x + dirX[d];
            int newY = y + dirY[d];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
                grid[newX][newY] == 1 && !visited[newX][newY]) {
                dfs(newX, newY);
            }
        }
    };

    // Mark all boundary lands
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1 && !visited[i][0]) dfs(i, 0);
        if (grid[i][m-1] == 1 && !visited[i][m-1]) dfs(i, m-1);
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1 && !visited[0][j]) dfs(0, j);
        if (grid[n-1][j] == 1 && !visited[n-1][j]) dfs(n-1, j);
    }

    // Now count closed islands
    int closed_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                closed_count++;
                dfs(i, j); // Mark this island as visited
            }
        }
    }
    return closed_count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << closedIsland(grid) << endl;
    return 0;
}
