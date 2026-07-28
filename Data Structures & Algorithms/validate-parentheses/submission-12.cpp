class Solution {
public:
    bool isValid(string s) {

        // If s.size() is less than or equal to 1 then it can never have matching opening and closing tags
        if(s.size() <= 1) return false;
        
        stack<char> open;

        for(const auto &currChar : s){

            if( currChar == '(' || currChar == '{' || currChar == '['  ){
                open.push(currChar);
            }
            else if( currChar == ')' || currChar == '}' || currChar == ']' ){
                if( !open.empty() && currChar == ')' && open.top() == '(' ) open.pop();
                else if( !open.empty() && currChar == '}' && open.top() == '{' ) open.pop();
                else if( !open.empty() && currChar == ']' && open.top() == '[' ) open.pop();
                else return false;

            }

        }

        // Should be empty if is a valid parentheses
        return open.empty();

    }
};
