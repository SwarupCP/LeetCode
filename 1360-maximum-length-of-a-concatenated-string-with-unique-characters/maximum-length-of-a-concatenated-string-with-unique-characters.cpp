class Solution {
public:
    bool hasDuplicate(string &s1, string &s2){
        int arr[26] = {0};

        for(char ch : s1){
            if(arr[ch - 'a'] > 0){
                return true;
            }
            arr[ch - 'a']++;
        }

        for(char ch : s2){
            if(arr[ch - 'a'] > 0){
                return true;
            }
        }

        return false;
    }
    int solve(int i, string temp, int n, vector<string>& arr){
        if(i >= n){
            return temp.length();
        }

        int include = 0;
        int exclude = 0;

        if(hasDuplicate(arr[i], temp)){
            exclude = solve(i + 1, temp, n, arr);
        }else{
            exclude = solve(i + 1, temp, n, arr);
            include = solve(i + 1, temp + arr[i], n, arr);
        }

        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(0, temp, n, arr);
    }
};