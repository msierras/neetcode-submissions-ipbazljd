class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

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