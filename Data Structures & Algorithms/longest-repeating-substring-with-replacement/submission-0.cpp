class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int maxChar = 0;
        int res = INT_MIN; 

        unordered_map<int, int> charCount; 

        for(int right = 0; right < s.size(); right++){

            charCount[s[right]]++;
            maxChar = max(maxChar, charCount[s[right]]);

            while( (right - left + 1) - maxChar > k){
                charCount[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);



        }


        return res;

    }
};
