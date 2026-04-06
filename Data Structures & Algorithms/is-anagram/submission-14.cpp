class Solution {
public:
    bool isAnagram(string s, string t) {
        // First check if both strings have the same length
        // If don't have same length then can never be valid anagrams of each other
        if(s.size() != t.size()){
            return false;
        }

        // HashMap that will contain the char and its number of counts for each string  
        unordered_map<char, int> sOccur;
        unordered_map<char, int> tOccur; 

        // Populating both HashMaps 
        for(int i = 0; i < s.size(); i ++){
            // this will go to each char key and increment by one
            sOccur[s[i]]++;
            tOccur[t[i]]++;
        }

        // If HashMaps are equal, that is if s and t are anagrams then will return true, otherwise will return false 
        return sOccur == tOccur;


        
    }
};
