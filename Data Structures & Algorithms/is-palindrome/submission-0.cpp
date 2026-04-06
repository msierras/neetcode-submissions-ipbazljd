#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        string newString = "";

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                newString += tolower(s[i]);
            }
        }

        if(newString == string(newString.rbegin(), newString.rend())){
            return true;
        }
        else{
            return false;
        }

    
    };
};
