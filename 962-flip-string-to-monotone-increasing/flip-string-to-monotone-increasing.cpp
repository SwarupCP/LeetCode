class Solution {
public:
    int n;
    int solve(string &s, int cur_index, int prev_val, vector<vector<int>> &dp){
        if(cur_index >= n){
            return 0;
        }

        if(dp[cur_index][prev_val] != -1){
            return dp[cur_index][prev_val];
        }

        int flip = INT_MAX;
        int notFlip = INT_MAX;

        if(s[cur_index] == '1'){
            if(prev_val == 1){
                notFlip = solve(s, cur_index + 1, 1, dp);
            }else{
                flip = 1 + solve(s, cur_index + 1, 0, dp);
                notFlip = solve(s, cur_index + 1, 1, dp);
            }
        }else{
            if(prev_val == 1){
                flip = 1 + solve(s, cur_index + 1, 1, dp);
            }else{
                flip = 1 + solve(s, cur_index + 1, 1, dp);
                notFlip = solve(s, cur_index + 1, 0, dp);
            }
        }

        return dp[cur_index][prev_val] = min(flip, notFlip);
    }
    int minFlipsMonoIncr(string s) {
        n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(s, 0, 0, dp);
    }
};