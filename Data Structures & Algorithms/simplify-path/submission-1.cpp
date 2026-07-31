class Solution {
public:
    string simplifyPath(string path) {

        vector<string> stk;

        // The string that we will make into a stream
        istringstream ss(path);

        string token, res;

        // Tokenizing path with delimiter '/'
        while( getline(ss, token, '/') ){
            if(token == "" || token == ".") continue;
            
            if(token != "..") stk.push_back(token);
            else if( token == ".." && !stk.empty() ) stk.pop_back();
        }

        for(const auto &str : stk) res+="/" + str;
        

        return stk.empty() ? "/":res;
    }
};