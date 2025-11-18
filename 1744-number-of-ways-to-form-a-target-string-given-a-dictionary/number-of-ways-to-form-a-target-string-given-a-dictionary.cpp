class Solution {
public:
    int m, k;
    const int MOD = 1e9 + 7;
    int solve(int i, int j, string &target, vector<vector<long long>>& freq, vector<vector<int>>& dp){
        if(i == m){
            return 1;
        }

        if(j == k){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int notTaken = solve(i, j + 1, target, freq, dp) % MOD;
        int taken = (freq[target[i] - 'a'][j] * solve(i + 1, j + 1, target, freq, dp)) % MOD;

        return dp[i][j] = (notTaken + taken) % MOD;
    }
    int numWays(vector<string>& words, string target) {
        m = target.length();
        k = words[0].length();

        vector<vector<long long>> freq(26, vector<long long>(k));
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, -1));

        for(int col = 0; col < k; col++){
            for(string &word : words){
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        return solve(0, 0, target, freq, dp);
    }
};