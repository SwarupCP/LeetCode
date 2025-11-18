class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int m = target.length();
        int k = words[0].length();

        vector<vector<long long>> freq(26, vector<long long>(k));
        vector<int> cur(k + 1, 0), next(k + 1, 0);

        for(int col = 0; col < k; col++){
            for(string &word : words){
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        for(int j = 0; j <= k; j++){
            next[j] = 1;
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = k - 1; j >= 0; j--){
                int notTaken = cur[j + 1] % MOD;
                int taken = (freq[target[i] - 'a'][j] * next[j + 1]) % MOD;

                cur[j] = (notTaken + taken) % MOD;
            }
            next = cur;
        }

        return next[0];
    }
};