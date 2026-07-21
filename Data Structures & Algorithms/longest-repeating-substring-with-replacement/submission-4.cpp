class Solution {
public:
    int characterReplacement(string s, int k) {

        // Will store the character Count of the current window 
        unordered_map<int, int> charCount; 

        int maxChar = 0;
        int res = INT_MIN; 

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            
            // Incrementing the count of current char
            // Don't need to know which char is the largest, just need to know largest value
            // since the smaller value is what gets replaced 
            charCount[s[right]]++;
            
            // Storing largest character count from charCount for current window
            maxChar = max(maxChar, charCount[s[right]]);

            // window - largest char cont > k 
            // If is greater than k then that means we need to move window to right
            // Will need to remove decrement the count of current char in
            // charCount and increment left
            while( (right - left + 1) - maxChar > k){
                charCount[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;

    }
};
