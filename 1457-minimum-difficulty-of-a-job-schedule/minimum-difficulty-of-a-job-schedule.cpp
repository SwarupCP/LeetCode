class Solution {
public:
    int solve(int idx, int d, int n, vector<int>& jobDifficulty, vector<vector<int>> &dp){
        if(d == 1){
            int maxD = jobDifficulty[idx];
            for(int i = idx; i < n; i++){
                maxD = max(maxD, jobDifficulty[i]);
            }
            return maxD;
        }

        if(dp[idx][d] != - 1){
            return dp[idx][d];
        }

        int maxResult = INT_MIN;
        int finalResult = INT_MAX;

        for(int i = idx; i <= n - d; i++){
            maxResult = max(maxResult, jobDifficulty[i]);
            int result = maxResult + solve(i + 1, d - 1, n, jobDifficulty, dp);
            finalResult = min(finalResult, result);
        }

        return dp[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d){
            return -1;
        }
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, -1));
        return solve(0, d, n, jobDifficulty, dp);
    }
};