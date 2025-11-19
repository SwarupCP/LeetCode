class Solution {
public:
    const int MOD = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();

        vector<vector<int>> cur(minProfit + 1, vector<int>(n + 1, 0)), next(minProfit + 1, vector<int>(n + 1, 0));

        for(int p = 0; p <= minProfit; p++){
            for(int people = 0; people <= n; people++){
                if(p >= minProfit){
                    next[p][people] = 1;
                }else{
                    next[p][people] = 0;
                }
            }
        }

        for(int i = group.size() - 1; i >= 0; i--){
            for(int p = minProfit; p >= 0; p--){
                for(int people = n; people >= 0; people--){
                    int notTake = next[p][people] % MOD;
                    int take = 0;
                    if(people + group[i] <= n){
                        take = next[min(p + profit[i], minProfit)][people + group[i]] % MOD;
                    }

                    cur[p][people] = (notTake + take) % MOD;
                }
            }
            next = cur;
        }

        return next[0][0];
    }
};