class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n + 1, 1);

        for(int i = 1; i < m; i++){
            vector<int> cur(n + 1, 1);
            for(int j = 1; j < n; j++){
                int left = cur[j - 1];
                int up = prev[j];

                cur[j] = left + up;
            }
            prev = cur;
        }
        
        return prev[n - 1];
    }
};