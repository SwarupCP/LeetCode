class Solution {
public:
    int M, N;
    int solve(int m, int n, vector<vector<int>>& dp){
        if(m == M && n == N){
            return 1;
        }

        if(m > M || n > N){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int down = solve(m + 1, n, dp);
        int right = solve(m, n + 1, dp);

        return dp[m][n] = down + right;
    }
    int uniquePaths(int m, int n) {
        M = m - 1;
        N = n - 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, dp);
    }
};