class Solution {
public:
    bool isPalindrome(string s) {

        string sFiltered;
        
        // isalnum() checks if char is A-Z, a-z, or 0,9
        for(auto const &character : s){
            if( isalnum(character) ) sFiltered += character;
        }


        int left = 0;
        int right = sFiltered.size() - 1;

        // the while loop makes sure left and right pointer don't collide 
        while(left < right){

            if( tolower(sFiltered[left]) != tolower(sFiltered[right])) return false;
            left++;
            right--;

        }

        return true;
    }
};
