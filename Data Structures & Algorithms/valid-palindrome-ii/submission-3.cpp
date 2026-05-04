class Solution {
private:
    bool isPalindrome(const string &s, int left, int right){
        while(left < right){
            if( s[left] != s[right] ){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            if( s[left] != s[right] ) {
                // Mismatch found: try skipping either the left or right character and check if either resulting substring is a palindrome.
                // Only checking one side will result in wrong answers
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
                // left+1 and right-1 are used instead of left++ and right-- because left+1 and right-1 compute new values without mutating left or right.
                // left++ would modify left after the first call, causing the second call to receive the wrong value.
            }

            left++;
            right--;

        }
        return true;
    }
};