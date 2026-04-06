class Solution {
    private:
        void gen_par_rec(int left, int right, int n, vector<string> &res, string str){
            if(left == n && right == n){
                res.push_back(str);
                return;
            }
            if(left < n){
                gen_par_rec(left + 1, right, n, res, str + '(');
            }
            if(right < left){
                gen_par_rec(left, right + 1, n, res, str + ')');
            }
        }

    public:
        vector<string> generateParenthesis(int n) {
            int left = 0;
            int right = 0;
            vector<string> res;

            gen_par_rec(left, right, n, res, ""); 

            return res; 
        };
};
