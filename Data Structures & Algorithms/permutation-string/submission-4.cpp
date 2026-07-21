class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // In s2 we have a window of size s1.size()
        // While window size is greater than s1.size() then do left++ and decrement that charCount
        // If the char count in that window is equal to the char count in s1 then return true, false otherwise


        if( s1.size() > s2.size() ) return false;


        unordered_map<char, int> s1CharCount;
        for(int i = 0; i < 26; i++) s1CharCount[ i + 'a' ] = 0;
        for(char &c : s1) s1CharCount[c]++;

        unordered_map<char, int> s2CharCount;
        for(int i = 0; i < 26; i++) s2CharCount[ i + 'a' ] = 0;


        int left = 0;
        for(int right = 0; right < s2.size(); right++){
            s2CharCount[s2[right]]++;

            if( right - left + 1 > s1.size() ){
                s2CharCount[s2[left]]--;
                left++; 
            }
            
            if( s2CharCount == s1CharCount ) return true;
        }


        return false;

    }
};