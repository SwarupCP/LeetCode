class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n + 1, 1);

        for(int i = m - 2; i >= 0; i--){
            vector<int> cur(n + 1, 1);
            for(int j = n - 2; j >= 0; j--){
                int down = prev[j];
                int right = cur[j + 1];

                cur[j] = down + right;
            }
            prev = cur;
        }

        return prev[0];
    }
};