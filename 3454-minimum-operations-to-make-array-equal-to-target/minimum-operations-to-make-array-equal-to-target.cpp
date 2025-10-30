class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        long long operation = 0;

        int prev = 0;
        int cur = 0;

        for(int i = 0; i < n; i++){
            cur = target[i] - nums[i];

            if((cur < 0 && prev > 0) || (cur > 0 && prev < 0)){
                operation += abs(cur);
            }else if(abs(cur) > abs(prev)){
                operation += (abs(cur) - abs(prev));
            }
            prev = cur;
        }
        return operation;
    }
};