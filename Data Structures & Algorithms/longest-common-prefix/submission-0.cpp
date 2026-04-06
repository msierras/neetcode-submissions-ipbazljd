class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Outer loop is looping through every character of the first string in strs 
        for (int i = 0; i < strs[0].length(); i++) {
            // For each string, check two cases:
            // 1) If i equals the string's length, meaning the string ended so the prefix cannot continue
            // 2) If the character at index i does not match the character at the same index in the first string
            // If either condition is true, the common prefix ends at index i, so return the substring from 0 to i
            for (const string& s : strs) {
                if (i == s.length() || s[i] != strs[0][i]) {
                    return s.substr(0, i);
                }
            }
        }
        
        // If we never encountered a mismatch, the entire first string is the common prefix
        return strs[0];
    }
};