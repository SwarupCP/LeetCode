class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int minCount = INT_MAX;

        for(int i = 1; i * i <= n; i++){
            int result = 1 + solve(n - i * i, dp);
            minCount = min(result, minCount);
        }

        return dp[n] = minCount;
    }
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

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
