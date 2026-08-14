class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int i = 0; i < asteroids.size(); i++) {
            // Only collide if current is negative AND top of stack is positive
            if (!res.empty() && res.back() > 0 && asteroids[i] < 0) {
                
                // Keep colliding while the current asteroid is still alive
                // and there's a positive asteroid ahead of it
                while (!res.empty() && res.back() > 0 && asteroids[i] < 0) {
                    
                    // Current asteroid is bigger → top of stack explodes
                    if (abs(asteroids[i]) > abs(res.back())) {
                        res.pop_back();
                    }
                    // Top of stack is bigger → current asteroid explodes
                    else if (abs(res.back()) > abs(asteroids[i])) {
                        asteroids[i] = 0;  // mark as exploded
                        break;
                    }
                    // Equal sizes → both explode
                    else {
                        res.pop_back();
                        asteroids[i] = 0;  // mark as exploded
                        break;
                    }
                }
                
                // If current asteroid survived all collisions, push it
                if (asteroids[i] != 0) {
                    res.push_back(asteroids[i]);
                }
            }
            // No collision → just push
            else {
                res.push_back(asteroids[i]);
            }
        }

        return res;
    }
};