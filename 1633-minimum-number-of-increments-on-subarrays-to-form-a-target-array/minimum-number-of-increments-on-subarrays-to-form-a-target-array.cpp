class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int operation = 0;

        int prev = 0;
        int cur = 0;

        for(int i = 0; i < n; i++){
            cur = target[i];
            if(abs(cur) > abs(prev)){
                operation += abs(cur - prev);
            }
            prev = cur;
        }
        return operation;
    }
};