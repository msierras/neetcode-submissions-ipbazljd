class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        // If two asteroids meet (top of res and currentAsteroid are different signs)
        //  1. Smaller one will explode
        //  2. If both are the same size, both will explode
        // NOTE: Consider the case where the currentAsteroid is negative
        //       and each abs(res.top()) is smaller than it 
        // Also consider the case where asteroid size is 0. We can probably just skip it with a "continue"


        // First check if our stack res is empty, if true then push currentAsteroid
        // Second, check if res.top() and currentAsteroid are different signs 
        // Third, check if currentAsteroid is 0, in which case we just "continue"
        // Fourth, currentAsteroid is positive, just push
        // , 

        vector<int> res;

        for(int i = 0; i < asteroids.size(); i++){

            int currentAsteroid = asteroids[i];

            if( res.empty() ){
                res.push_back( currentAsteroid );
            }
            else if( currentAsteroid == 0 ){
                continue;
            }
            else if( currentAsteroid > 0 ){
                res.push_back( currentAsteroid );
            }
            else{   // currentAsteroid is negative

                while( !res.empty() && res.back() > 0 && abs(currentAsteroid) > res.back() ){
                    res.pop_back();
                }

                if( !res.empty() && res.back() > 0 && res.back() > abs(currentAsteroid) ){
                    continue;
                }
                else if( !res.empty() && res.back() > 0 && res.back() == abs(currentAsteroid) ){
                    res.pop_back();
                    continue;
                }
                else{
                    res.push_back( currentAsteroid );

                }

            }


        }

        return res;

    }
};