class Solution {
public:
    int lengthOfLongestSubstring(string s) {   

        unordered_set<char> window; 
        int left = 0;
        int longestSubStr = 0;
        int windowSize;

        for(int right = 0; right < s.size(); right++){

            while( window.contains( s[right] ) ){
                window.erase( s[left] );
                left++; 
            }

            window.insert( s[right] );
            
            windowSize = window.size();
            longestSubStr = max( longestSubStr, windowSize );
        }

        return longestSubStr; 


    }
};
