class Solution {
public:
    int n;
    int solve(int i, int k, vector<vector<int>>& piles, vector<vector<int>>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i][k] != -1){
            return dp[i][k];
        }

        int notTaken = solve(i + 1, k, piles, dp);
        int taken = 0;
        int sum = 0;

        for(int j = 0; j < min((int)piles[i].size(), k); j++){
            sum += piles[i][j];

            taken = max(taken, sum + solve(i + 1, k - (j + 1), piles, dp));
        }

        return dp[i][k] = max(taken, notTaken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, piles, dp);
    }
};