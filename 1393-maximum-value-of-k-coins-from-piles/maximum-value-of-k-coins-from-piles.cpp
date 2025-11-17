class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();

        vector<int> next(k + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            vector<int> cur(k + 1, 0);
            for(int j = k; j >= 1; j--){
                int notTaken = next[j];
                int taken = 0;
                int sum = 0;

                for(int x = 0; x < min((int)piles[i].size(), j); x++){
                    sum += piles[i][x];

                    taken = max(taken, sum + next[j - (x + 1)]);
                }

                cur[j] = max(taken, notTaken);
            }
            next = cur;
        }
        return next[k];
    }
};