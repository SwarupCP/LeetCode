class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int m = target.length();
        int k = words[0].length();

        vector<vector<long long>> freq(26, vector<long long>(k));
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));

        for(int col = 0; col < k; col++){
            for(string &word : words){
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        for (int j = 0; j <= k; j++) {
            dp[m][j] = 1;
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = k - 1; j >= 0; j--){
                int notTaken = dp[i][j + 1] % MOD;
                int taken = (freq[target[i] - 'a'][j] * dp[i + 1][j + 1]) % MOD;

                dp[i][j] = (notTaken + taken) % MOD;
            }
        }

        return dp[0][0];
    }
};