class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size() - 1;

        // the while loop makes sure left and right pointer don't collide 
        while(left < right){
            // left pointer keeps incrementing till it encounters a character that is 
            // A-Z, a-z, or 0-9
            while( left < right && !isalnum(s[left]) ){
                left++;
            }
            // right pointer keeps decrementing till it encounters a charcater that is 
            // A-Z, a-z, or 0,9
            while( right > left && !isalnum(s[right]) ){
                right--;
            }

            // need to make characters to lowercase since they may be uppercase 
            if( tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;

        }

        return true;
    }
};
