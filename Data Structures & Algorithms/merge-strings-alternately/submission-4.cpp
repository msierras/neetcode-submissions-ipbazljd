class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left = 0;
        int right = word1.size() ;
        string res = "";

        while(left < right && left < word1.size() && left < word2.size()){

            res += word1[left];
            res += word2[left];

            left++;
        }

        if( word1.size() > word2.size() ){
            string temp = word1.substr( word2.size(), word1.size() );
            res += temp;
        }
        else if( word2.size() > word1.size() ){
            string temp = word2.substr( word1.size(), word2.size() );
            res += temp;
        }

       return res; 

    }
};