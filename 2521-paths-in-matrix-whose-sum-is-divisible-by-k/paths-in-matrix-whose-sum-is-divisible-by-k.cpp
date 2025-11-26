class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0)));

        for(int curSum = 0; curSum < k; curSum++){
            if(((curSum + grid[m - 1][n - 1]) % k) == 0){
                dp[m - 1][n - 1][curSum] = 1;
            }
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1) continue; 
                for(int curSum = 0; curSum < k; curSum++){
                    int down = dp[i + 1][j][(curSum + grid[i][j]) % k] % MOD;
                    int right = dp[i][j + 1][(curSum + grid[i][j]) % k] % MOD;
            
                    dp[i][j][curSum] = (down + right) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};