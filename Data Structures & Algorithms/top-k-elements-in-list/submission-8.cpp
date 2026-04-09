class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;    // Creation of a hashmap that will have an int as its key and its number of occurences as its value. 
        for(const int &num: nums){  // populating the hash map with ints and their number of occurrences
            map[num]++;
        }

        vector< vector<int> > buckets(nums.size() + 1); // adding 1 to nums.size() since it's zero indexed.
        for(const auto &x: map){
            buckets[x.second].push_back(x.first);
        }
        
        vector<int> result;
        for(int i = buckets.size() - 1;  result.size() < k; i-- ){  // subtracting 1 to buckets.size() to make it zero indexed again. 
            for(const int &num: buckets[i]){    // while inside the bucket[i] we add the number(s) in that bucket, i.e, if we're inside the bucket that contains all the numbers that 
                result.push_back(num);          // occur 3 times then we add one number to result while result.size() < k.
            }
        }

        return result;

    }
};
