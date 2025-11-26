class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    int solve(int i, int j, int curSum, int k, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i >= m || j >= n){
            return 0;
        }

        if(i == m - 1 && j == n - 1){
            return (curSum + grid[i][j]) % k == 0 ? 1 : 0;
        }

        if(dp[i][j][curSum] != -1){
            return dp[i][j][curSum];
        }

        int down = solve(i + 1, j, (curSum + grid[i][j]) % k, k, grid, dp) % MOD;
        int right = solve(i, j + 1, (curSum + grid[i][j]) % k, k, grid, dp) % MOD;

        return dp[i][j][curSum] = (down + right) % MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(0, 0, 0, k, grid, dp);
    }
};