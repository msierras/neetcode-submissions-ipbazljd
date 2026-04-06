class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // HashMap where key is the sorted string and value
        // contains a vector of the strings that match
        // the key
        unordered_map< string, vector<string> > hm; 

        // Populating HashMap
        for(const string s : strs){
            string sSorted = s;
            sort( sSorted.begin(), sSorted.end() );
            hm[sSorted].push_back(s);  
        }

        vector< vector<string> > res; 

        for(const auto &val : hm){
            res.push_back(val.second);
        }

        return res; 
        

    }
};
