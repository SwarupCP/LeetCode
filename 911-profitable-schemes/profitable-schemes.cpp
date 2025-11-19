class Solution {
public:
    int N;
    const int MOD = 1e9 + 7;
    int solve(int i, int p, int people, int &minProfit, vector<int>& group, vector<int>& profit, vector<vector<vector<int>>>& dp){
        if(people > N){
            return 0;
        }

        if(i == group.size()){
            if(p >= minProfit){
                return 1;
            }else{
                return 0;
            }
        }

        if(dp[i][p][people] != -1){
            return dp[i][p][people];
        }

        int notTake = solve(i + 1, p, people, minProfit, group, profit, dp) % MOD;
        int take = solve(i + 1, min(p + profit[i], minProfit), people + group[i], minProfit, group, profit, dp) % MOD;

        return dp[i][p][people] = (notTake + take) % MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(0, 0, 0, minProfit, group, profit, dp);
    }
};