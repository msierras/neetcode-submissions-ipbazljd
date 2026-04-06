class Solution {
public:
    string encode(vector<string>& strs) {
        string res; 
        for(string str: strs){
            res += to_string(str.size()) + "#" + str;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res; 

        for(int i = 0; i < s.size(); i++){
            int j = i;
            
            while(s[j] != '#') j++;

            int len = stoi( s.substr(i, j) );

            res.push_back(s.substr(j + 1,len));

            i = j + len;

        }

        return res; 

    }

};