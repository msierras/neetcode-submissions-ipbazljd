class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(const auto &str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    // 5#Hello5#World

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        int j;

        while( i < s.size() ){
            j = i;


            while(s[j] != '#'){
                j++;
            }
            
            int len = stoi(s.substr(i, j));

            // The +1 moves to start of string 
            res.push_back(s.substr(j + 1, len));

            // Without the +1, in the next iteration, i will start at a
            // character instead of a number
            i = j + len + 1;
        }

        return res;
    }
};
