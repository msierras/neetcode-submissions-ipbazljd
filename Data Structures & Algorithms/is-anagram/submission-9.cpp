
class Solution {
public:
    bool isAnagram(string s, string t) {
       
       /*
        If string s and string t have different lengths then 
        they automatically will not have the same number of 
        characters, so we return false. 
       */ 
       if(s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if( s == t ){
            return true;
        }
        else{
            return false;
        }

    }
};
