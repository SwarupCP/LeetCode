class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();

        vector<int> prev(2, 0), cur(2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int prev_val = 1; prev_val >= 0; prev_val--){
                int flip = INT_MAX;
                int notFlip = INT_MAX;

                if(s[i] == '1'){
                    if(prev_val == 1){
                        notFlip = cur[1];
                    }else{
                        flip = 1 + cur[0];
                        notFlip = cur[1];
                    }
                }else{
                    if(prev_val == 1){
                        flip = 1 + cur[1];
                    }else{
                        flip = 1 + cur[1];
                        notFlip = cur[0];
                    }
                }
                cur[prev_val] = min(flip, notFlip);
            }
            prev = cur;
        }

        return cur[0];
    }
};