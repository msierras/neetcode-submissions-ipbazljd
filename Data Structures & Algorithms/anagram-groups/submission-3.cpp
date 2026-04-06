#include <cstring>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // hashmap that will contain a sorted string as a key and the value will be a vector of all the strings that are anagrams of it  
        unordered_map<string, vector<string> > map;
        // ans will contain the vectors of strings that are anagrams
        vector< vector<string> > ans;

        // populating hashmap
        for(const string &s: strs){
            string sSorted = s; 
            sort(sSorted.begin(), sSorted.end());
            map[sSorted].push_back(s);
        }

        // adding vectors of anagrams to ans 
        for(const pair< const string, const vector<string> > &x: map){
            ans.push_back( move(x.second) );    
            // move() transfers the contents of x.second into ans without copying.
            // After this, x.second is left in a valid but unspecified (essentially empty) state.
            // This improves performance by avoiding a deep copy of the vector.
        }

        // returning the grouped anagrams 
        return ans;
    }
};
