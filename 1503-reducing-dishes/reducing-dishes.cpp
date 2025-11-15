class Solution {
public:
    int n;
    int solve(int i, int time, vector<int>& satisfaction, vector<vector<int>>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i][time] != - 1){
            return dp[i][time];
        }

        int include = satisfaction[i] * time + solve(i + 1, time + 1, satisfaction, dp);
        int exclude = solve(i + 1, time, satisfaction, dp);

        return dp[i][time] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, 1, satisfaction, dp);
    }
};