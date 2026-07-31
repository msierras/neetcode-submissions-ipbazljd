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
            else if(token != "..") stk.push_back(token);
            else if( token == ".." && !stk.empty() ) stk.pop_back();    // ".." means we have to delete previous directory
        }

        // Populating res with values in stk
        for(const auto &str : stk) res+="/" + str;
        
        // In the case that stk is empty we return just "/"", else return res
        return stk.empty()?"/":res;
    }
};