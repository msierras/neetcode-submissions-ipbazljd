class Solution {
public:
    bool isPalindrome(string s) {

        string sFiltered = "";

        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) sFiltered += s[i];
        }

        // if(sFiltered.size() % 2 != 0) return false;

        int left = 0;
        int right = sFiltered.size() - 1;

        while(left < right){

            if( tolower(sFiltered[left]) != tolower(sFiltered[right])) return false;
            left++;
            right--;
        }

        return true;


    }
};
