class Solution {
public:
    bool isAnagram(string s, string t) {
        // First check if both strings have the same length
        // If don't have same length then can never be valid anagrams of each other
        if(s.size() != t.size()){
            return false;
        }

        // HashMap that will contain the char and its number of counts 
        unordered_map<char, int> sOccur;
        unordered_map<char, int> tOccur; 
        for(int i = 0; i < s.size(); i ++){
            sOccur[s[i]]++;
            tOccur[t[i]]++;
        }

        return sOccur == tOccur;


        
    }
};
