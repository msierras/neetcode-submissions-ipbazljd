class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Creation of a hashmap that will have an int as its key and its number of occurences as its value. 
        unordered_map<int, int> map;
        for(const int &num: nums){
            map[num]++;
        }

        unordered_map< int, vector<int> > buckets(nums.size() - 1);
        for(auto x: map){
            buckets[x.second].push_back(x.first);
        }
        
        vector<int> result;
        for(int i = nums.size() + 1;  result.size() < k; i-- ){
            for(int num: buckets[i]){
                result.push_back(num);
            }
        }

        return result;

    }
};
