class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n != s2.size()) return false;
        if (s1 == s2) return true;

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {

                    bool possible = false;

                    for (int k = 1; k < len; k++) {

                        if (dp[i][j][k] && dp[i + k][j + k][len - k]) {
                            possible = true;
                            break;
                        }

                        if (dp[i][j + len - k][k] && dp[i + k][j][len - k]) {
                            possible = true;
                            break;
                        }
                    }

                    dp[i][j][len] = possible;
                }
            }
        }

        return dp[0][0][n];
    }
};
