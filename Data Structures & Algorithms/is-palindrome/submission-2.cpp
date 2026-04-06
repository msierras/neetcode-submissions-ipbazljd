#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        string newString;

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){  // isalnum() checks if a character is alphanumeric, meaning if it is a letter (upper or lower) or number.
                newString += tolower(s[i]); // if it is uppercase we change it to lowercase
            }
        }

        if(newString == string(newString.rbegin(), newString.rend())){  // if newString is equal to its reverse 
            return true;
        }
        else{
            return false;
        }

    
    };
};
