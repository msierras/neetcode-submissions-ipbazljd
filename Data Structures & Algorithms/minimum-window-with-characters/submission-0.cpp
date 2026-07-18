class Solution {
public:
    string minWindow(string s, string t) {

        // If t is empty then the shortest substring of s such that every character in t,
        // including duplicates, is present in the substring does not exist, so return
        // an empty string.
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        
        // Counting occurrence of each char in t
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int res = -1;
        int resLen = INT_MAX;   // resLen is made INT_MAX so first pass works 
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            // Incrementing windows current char count
            char c = s[r];
            window[c]++;

            // If the HM contains the current char and the count for the char in window and countT are equal,
            // increment have
            if (countT.contains(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {  
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = l;
                }

                window[s[l]]--; // Decrementing window char at index l
                if (countT.contains(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        // resLen returns INT_MAX if no substring is found
        // else returns the substring with smallest length 
        return resLen == INT_MAX ? "" : s.substr(res, resLen);
    }
};