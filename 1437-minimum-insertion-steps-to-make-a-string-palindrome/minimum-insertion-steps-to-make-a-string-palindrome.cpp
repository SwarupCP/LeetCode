class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> cur(n + 1, 0), next(n + 1, 0);

        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j <= n - 1; j++){
                if(s[i] == s[j]){
                    cur[j] = next[j - 1];
                }else{
                    cur[j] = 1 + min(next[j], cur[j - 1]);
                }
            }
            next = cur;
        }

        return next[n - 1];
    }
};