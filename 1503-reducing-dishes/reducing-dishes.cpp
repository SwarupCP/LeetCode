class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> cur(n + 2, 0), next(n + 2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int time = n; time >= 1; time--){
                int include = satisfaction[i] * time + next[time + 1];
                int exclude = next[time];

                cur[time] = max(include, exclude);
            }
            next = cur;
        }

        return cur[1];
    }
};