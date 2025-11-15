class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int time = n; time >= 1; time--){
                int include = satisfaction[i] * time + dp[i + 1][time + 1];
                int exclude = dp[i + 1][time];

                dp[i][time] = max(include, exclude);
            }
        }

        return dp[0][1];
    }
};