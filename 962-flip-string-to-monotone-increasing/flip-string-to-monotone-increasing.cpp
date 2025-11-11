class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int prev_val = 0; prev_val <= 1; prev_val++){
                int flip = INT_MAX;
                int notFlip = INT_MAX;

                if(s[i] == '1'){
                    if(prev_val == 1){
                        notFlip = dp[i + 1][1];
                    }else{
                        flip = 1 + dp[i + 1][0];
                        notFlip = dp[i + 1][1];
                    }
                }else{
                    if(prev_val == 1){
                        flip = 1 + dp[i + 1][1];
                    }else{
                        flip = 1 + dp[i + 1][1];
                        notFlip = dp[i + 1][0];
                    }
                }
                dp[i][prev_val] = min(flip, notFlip);
            }
        }

        return dp[0][0];
    }
};