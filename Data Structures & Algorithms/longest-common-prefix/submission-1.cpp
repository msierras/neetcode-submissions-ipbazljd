class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].length(); i++){
            for(const string &str: strs){
                if( i == str.length() || str[i] != strs[0][i]){
                    return str.substr(0, i);
                }
            }
        }

        return strs[0]; 
    }
};