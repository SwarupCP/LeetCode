class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> cur(n + 2, 0), next(n + 2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int time = n; time >= 1; time--){
                cur[time] = max(satisfaction[i] * time + next[time + 1], next[time]);
            }
            next = cur;
        }

        return next[1];
    }
};