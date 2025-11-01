class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            int minCount = INT_MAX;

            for(int j = 1; j * j <= i; j++){
                int result = 1 + dp[i - j * j];
                minCount = min(result, minCount);
            }

            dp[i] = minCount;
        }

        return dp[n];
    }
};