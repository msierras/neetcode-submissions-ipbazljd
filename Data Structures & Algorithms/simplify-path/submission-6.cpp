class Solution {
public:
    string simplifyPath(string path) {
        // Use '/' as a delimiter, then go through it:
        // If empty then skip it, 
        // If ".." and res is not empty then pop 
        // Else push to res while prefixing a "/"
        
        vector<string> stk;
        string res;

        stringstream check1(path);
        string token;

        while(getline(check1, token, '/')){
            
            if(token == "" || token == "." || (stk.empty() && token == "..") ) continue;
            else if( !stk.empty() && token == "..") stk.pop_back();
            else stk.push_back( "/" + token );
        }



        for(int i = 0; i < stk.size(); i++){
            cout << stk[i];
            res += stk[i];
        }




        return stk.empty() ? "/": res;



    }
};