class Solution {
public:
    int n;
    int getNextIndex(int start, int currentJobEnd, vector<vector<int>>& array){
        int end = n - 1;
        int result = n + 1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(array[mid][0] >= currentJobEnd){
                result = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return result;
    }
    int solve(int i, vector<vector<int>>& array, vector<int>& dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int next = getNextIndex(i + 1, array[i][1], array);

        int take = array[i][2] + solve(next, array, dp);
        int notTake = solve(i + 1, array, dp);

        return dp[i] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        vector<vector<int>> array(n, vector<int>(3, 0));
        vector<int> dp(n + 1, -1);

        for(int i = 0; i < n; i++){
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        sort(array.begin(), array.end());

        return solve(0, array, dp);
    }
};

class Solution {
public:
    int n;
    int getNextIndex(int start, int currentJobEnd, vector<vector<int>>& array){
        int end = n - 1;
        int result = n;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(array[mid][0] >= currentJobEnd){
                result = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        return result;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        vector<vector<int>> array(n, vector<int>(3, 0));
        vector<int> dp(n + 1, 0);

        for(int i = 0; i < n; i++){
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }

        sort(array.begin(), array.end());

        for(int index = n - 1; index >= 0; index--){
            int next = getNextIndex(index + 1, array[index][1], array);

            int take = array[index][2] + dp[next];
            int notTake = dp[index + 1];

            dp[index] = max(take, notTake);
        }

        return dp[0];
    }
};
