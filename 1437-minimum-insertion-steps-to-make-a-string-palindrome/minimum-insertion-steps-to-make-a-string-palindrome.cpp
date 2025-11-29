class Solution {
public:
    int n;
    int solve(int i, int j, string &s, vector<vector<int>>& dp){
        if(i >= j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return solve(i + 1, j - 1, s, dp);
        }

        return dp[i][j] = 1 + min(solve(i + 1, j, s, dp), solve(i, j - 1, s, dp));
    }
    int minInsertions(string s) {
        n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, s, dp);
    }
};