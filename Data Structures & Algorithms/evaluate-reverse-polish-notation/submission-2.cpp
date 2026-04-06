class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // this stack will contain the numbers we encounter in tokens 
        stack<int> stack; 

        for(auto element: tokens){
            
            if(element != "+" && element!= "-" && element != "*" && element != "/"){ // if element is a number string
                stack.push(stoi(element));    // we push element onto the stack 
            }
            else if(element == "+"){   // in the case where element is "+" operator 
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 + op2);
            }
            else if(element == "-"){   // in the case where element is "-" operator 
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 - op2);
            }
            else if(element == "*"){   // in the case where element is "*" operator 
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 * op2);
            }
            else if(element == "/"){   // in the case where element is "/" operator 
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 / op2);
            }

        }


        
        return stack.top(); 


    }
};
