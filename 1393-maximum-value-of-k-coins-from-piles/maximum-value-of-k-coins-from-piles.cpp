class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = k; j >= 1; j--){
                int notTaken = dp[i + 1][j];
                int taken = 0;
                int sum = 0;

                for(int k = 0; k < min((int)piles[i].size(), j); k++){
                    sum += piles[i][k];

                    taken = max(taken, sum + dp[i + 1][j - (k + 1)]);
                }

                dp[i][j] = max(taken, notTaken);
            }
        }
        return dp[0][k];
    }
};