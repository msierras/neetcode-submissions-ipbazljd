class Solution {
    private:
        void gen_par_rec(int left, int right, int n, vector<string> &res, string str){
            // for the base case we check that right == n since right can only ever equal left or be less than left. 
            // this is due to the if statements below the base case. So, when right == n we know that it must equal to left which will also be equal to n. 
            if(right == n){
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
            vector<string> res;

            gen_par_rec(0, 0, n, res, ""); 

            return res; 
        };
};
