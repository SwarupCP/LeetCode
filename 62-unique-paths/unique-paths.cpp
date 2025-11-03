class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                int down = dp[i + 1][j];
                int right = dp[i][j + 1];

                dp[i][j] = down + right;
            }
        }

        return dp[0][0];
    }
};