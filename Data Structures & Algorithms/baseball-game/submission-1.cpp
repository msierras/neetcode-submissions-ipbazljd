class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stck;


        for(string operation : operations){
 
            if( operation == "+" ){
                stck.push_back( stck[stck.size()-1] + stck[stck.size()-2] );
            }
            else if( operation == "D" ){
                stck.push_back( stck[stck.size() - 1] * 2 );
            }
            else if( operation == "C" ){
                stck.pop_back();
            }
            else{   // When 
                stck.push_back( std::stoi(operation) );
            }


        }

        int res = 0;
        for(auto element : stck){
            res += element;
        }

        return res;

    }
};