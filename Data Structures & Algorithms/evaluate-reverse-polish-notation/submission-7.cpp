class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> res;

        for(int i = 0; i < tokens.size(); i++){

            if( tokens[i] == "+" ){ 
                int a = res.top();
                res.pop();

                int b = res.top();
                res.pop();

                res.push( a + b );
            }
            else if( tokens[i] == "-" ){
                int b = res.top();
                res.pop();

                int a = res.top();
                res.pop();

                res.push( a - b );
            }
            else if( tokens[i] == "*" ){
                int a = res.top();
                res.pop();

                int b = res.top();
                res.pop();

                res.push( a * b );
            }
            else if( tokens[i] == "/" ){
                int b = res.top();
                res.pop();

                int a = res.top();
                res.pop();

                res.push( a / b );
            }
            else res.push( stoi(tokens[i]) );

        }

        // Final result should be on the top of the stack 
        return res.top();

    }
};
