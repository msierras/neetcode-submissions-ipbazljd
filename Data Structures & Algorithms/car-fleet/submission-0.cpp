class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
           
        
        // vector that will pair car's position to the amount of time it will take to reach the target 
        vector< pair<int, double> > cars;

        // pairing up a car's position to the amount of time it will take to reach the target 
        for(int i = 0; i < position.size(); i++){
            double time = ((double) target - (double) position[i]) / (double) speed[i];
            cars.push_back( {position[i], time} );
        }

        // sorting cars to descending order
        sort(cars.rbegin(), cars.rend());


        // res is 1 since there will always be at least one fleet 
        int res = 1; 
        stack<double> stck;

        for(int j = 0; j < position.size(); j++){
            if(stck.empty()){
                stck.push(cars[j].second);
            }
            if(!(stck.empty()) && cars[j].second > stck.top()){
                stck.push(cars[j].second);
            }
            
        }



        return res + stck.size() - 1;
    }
};
