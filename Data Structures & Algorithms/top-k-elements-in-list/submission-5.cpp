class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;    // Creation of a hashmap that will have an int as its key and its number of occurences as its value. 
        for(const int &num: nums){  // populating the hash map with ints and their number of occurrences
            map[num]++;
        }

        vector< vector<int> > buckets(nums.size() + 1); // adding 1 to nums.size() since it's zero indexed.
        for(const pair<const int, const int> &x: map){
            buckets[x.second].push_back(x.first);
        }
        
        vector<int> result;
        for(int i = buckets.size() - 1;  result.size() < k; i-- ){  // subtracting 1 to buckets.size() to make it zero indexed again. 
            for(const int num: buckets[i]){
                result.push_back(num);
            }
        }

        return result;

    }
};
