class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int word1Right = word1.size(), word2Right = word2.size();
        string res;

        // This for loop will add a char from either string as long as that string is not at its end 
        for (int left = 0; left < word1Right || left < word2Right; left++) { // add character from each string if that index is valid 
            if (left < word1Right) {
                res += word1[left];
            }
            if (left < word2Right) {
                res += word2[left];
            }
        }

        return res;
    }
};