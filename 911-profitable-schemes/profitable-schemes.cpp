class Solution {
public:
    const int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int N = n;
        int m = group.size();
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, 0)));

        for(int p = 0; p <= minProfit; p++){
            for(int people = 0; people <= N; people++){
                if(p >= minProfit){
                    dp[m][p][people] = 1;
                }else{
                    dp[m][p][people] = 0;
                }
            }
        }

        for(int i = group.size() - 1; i >= 0; i--){
            for(int p = minProfit; p >= 0; p--){
                for(int people = N; people >= 0; people--){
                    int notTake = dp[i + 1][p][people] % MOD;
                    int take = 0;
                    if(people + group[i] <= N){
                        take = dp[i + 1][min(p + profit[i], minProfit)][people + group[i]] % MOD;
                    }

                    dp[i][p][people] = (notTake + take) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};