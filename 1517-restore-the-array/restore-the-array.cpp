class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int start = n - 1; start >= 0; start--){

            if(s[start] == '0'){
                dp[start] = 0;
                continue;
            }

            long ans = 0;
            long long num = 0;

            for(int end = start; end < n; end++){
                num = (num * 10) + (s[end] - '0');

                if(num > k){
                    break;
                }

                ans = (ans % MOD + dp[end + 1] % MOD) % MOD;
            }

            dp[start] = ans;
        }

        return dp[0];
    }
};