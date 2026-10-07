class Solution {
public:
    string decodeString(string s) {
        
        stack<int> nums;
        string currInt;

        stack<string> strs;
        string currStr;

        for(const auto &c : s){

            if( isdigit(c) ){
                currInt += c;
            }
            else if( c == '[' ){
                nums.push( stoi(currInt) );
                currInt = "";

                strs.push( currStr );
                currStr = "";
            }   
            else if( c == ']' ){
                string temp = currStr;
                currStr = strs.top();
                strs.pop();

                for(int i = 0; i < nums.top(); i++){
                    currStr += temp;
                }

                nums.pop();
            }
            else{
                currStr += c;
            }

        }

        return currStr;
    }
};