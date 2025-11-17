class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<int> cur(k + 1, 0), next(k + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = k; j >= 1; j--){
                int notTaken = next[j];
                int taken = 0;
                int sum = 0;

                for(int k = 0; k < min((int)piles[i].size(), j); k++){
                    sum += piles[i][k];

                    taken = max(taken, sum + next[j - (k + 1)]);
                }

                cur[j] = max(taken, notTaken);
            }
            next = cur;
        }
        return next[k];
    }
};