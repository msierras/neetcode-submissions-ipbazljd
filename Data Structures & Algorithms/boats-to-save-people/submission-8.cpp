class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // First, check if people[left] + people[right] <= limit
        // Second, check if people[left] <= limit
        // Third, check if peopleright <= limit

        int left = 0;
        int res = 0;
        int right = people.size() - 1;
        
        sort( people.begin(), people.end() );

        while(left <= right){
            
            if( people[left] + people[right] <= limit  ){
                left++;
                right--; 
                res++;
            }
            else if( people[right] <= limit ){
                right--;
                res++;
            }
            else if( people[left] <= limit){
                left++;
                res++;
            }





        }

        return res;



    }
};