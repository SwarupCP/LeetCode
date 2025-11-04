class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, false);
        dp[n - 1] = true;

        for(int idx = n - 2; idx >= 0; idx--){
            for(int i = 1; i <= nums[idx] && (idx + i < n); i++){
                if(dp[idx + i] == true){
                    dp[idx] = true;
                }
            }
        }
        
        return dp[0];
    }
};