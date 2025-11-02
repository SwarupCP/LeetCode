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
