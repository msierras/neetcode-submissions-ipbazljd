class Solution {
public:
    int lengthOfLongestSubstring(string s) {

     // We're given a string s and we need to find the length of the longest substring without duplicate characters
     //  First thought that comes to mind is that we need a sliding window and neeed to use a set to filter out duplicate characters
     //  We can calculate the length by doing right - left + 1?
     //  When we encounter a duplicate character on the right we keep incrementing left till there is no longer a duplicate character in the set
    
    int left = 0;
    int res = INT_MIN; 

    unordered_set<char> window; 


    for(int right = 0; right < s.size(); right++){

        while( window.contains( s[right] ) ){
            window.erase( s[left] );
            left++;
        }


        // Inserting char from s at index right
        window.insert( s[right] );
        res = max( right - left + 1, res);



    }


    if( res == INT_MIN ) return 0;
    else return res;


    }
};
