class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // If current car's time is less than or equal to the top of the stack, it joins the same fleeet, else it forms a new fleet
        // The lenght of the stack at the end will represent the number of fleets formed

        stack<float> timeStack;

        vector< pair<int,int> > cars;

        // Populating cars
        for(int i = 0; i < position.size(); i++){
            cars.push_back( {position[i], speed[i]} );
        }

        // Sorting in descending order
        sort( cars.rbegin(), cars.rend() );


        for(int i = 0; i < position.size(); i++){

            double time = (double) (target - cars[i].first) / cars[i].second;

            if( !timeStack.empty() && time > timeStack.top() ){
                timeStack.push( time );
            }
            else if( !timeStack.empty() && time <= timeStack.top() ){
                continue;
            }
            else if ( timeStack.empty() ){
                timeStack.push( time );
            }

        }



        return timeStack.size();
    }
};
