class Solution {
public:
    string decodeString(string s) {
        vector<string> stringStack;
        vector<int> countStack;
        string cur = "";
        string digits = "";

        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            } else if (c == '[') {
                stringStack.push_back(cur);
                countStack.push_back(stoi(digits));
                cur = "";
                digits = "";
            } else if (c == ']') {
                string temp = cur;
                cur = stringStack.back();
                stringStack.pop_back();
                int count = countStack.back();
                countStack.pop_back();
                for (int i = 0; i < count; i++) {
                    cur += temp;
                }
            } else {
                cur += c;
            }
        }

        return cur;
    }
};