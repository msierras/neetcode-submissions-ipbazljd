#include <cstring>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > map;
        vector< vector<string> > ans;

        for(string s: strs){
            string sSorted = s; 
            sort(sSorted.begin(), sSorted.end());
            map[sSorted].push_back(s);
        }

        for(auto x: map){
            ans.push_back(x.second);
        }

        return ans;
    }
};
