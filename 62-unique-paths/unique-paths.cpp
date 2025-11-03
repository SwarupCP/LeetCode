class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp){
        if(m == 0 && n == 0){
            return 1;
        }

        if(m < 0 || n < 0){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int left = solve(m, n - 1, dp);
        int up = solve(m - 1, n, dp);

        return dp[m][n] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(m - 1, n - 1, dp);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int left = dp[i][j - 1];
                int up = dp[i - 1][j];

                dp[i][j] = left + up;
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

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

class Solution {
public:
    int M, N;
    int solve(int m, int n, vector<vector<int>>& dp){
        if(m == M && n == N){
            return 1;
        }

        if(m > M || n > N){
            return 0;
        }

        if(dp[m][n] != -1){
            return dp[m][n];
        }

        int down = solve(m + 1, n, dp);
        int right = solve(m, n + 1, dp);

        return dp[m][n] = down + right;
    }
    int uniquePaths(int m, int n) {
        M = m - 1;
        N = n - 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, dp);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 2; j >= 0; j--){
                int down = dp[i + 1][j];
                int right = dp[i][j + 1];

                dp[i][j] = down + right;
            }
        }

        return dp[0][0];
    }
};

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
