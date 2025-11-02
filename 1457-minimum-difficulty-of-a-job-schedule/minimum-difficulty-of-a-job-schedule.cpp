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

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d){
            return -1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            int maxD = jobDifficulty[i];
            for (int j = i; j < n; j++) {
                maxD = max(maxD, jobDifficulty[j]);
            }
            dp[i][1] = maxD;
        }

        for(int day = 2; day <= d; day++){
            for(int i = 0; i <= n - day; i++){
                int maxResult = INT_MIN;
                int finalResult = INT_MAX;
                
                for(int j = i; j <= n - day; j++){
                    maxResult = max(maxResult, jobDifficulty[j]);
                    if(dp[j + 1][day - 1] != INT_MAX){
                        int result = maxResult + dp[j + 1][day - 1];
                        finalResult = min(finalResult, result);
                    }
                }

                dp[i][day] = finalResult;
            }
        }

        return dp[0][d];
    }
};
