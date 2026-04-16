class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hm;
        
        // Gets the number of occurrences for each num
        for(const auto &num : nums){
            hm[num]++;
        }

        // Will hold our buckets
        vector<vector<int>> bkt(nums.size() + 1);\
        // Adding each number to the bucket that represents their number of occurrence
        // i.e., 1 has 7 occurrences so it goes into the 7th bucket
        for(const auto & x : hm){
            bkt[x.second].push_back(x.first);
        }

        vector<int> res;
        for(int i = bkt.size() - 1; res.size() < k; i--){
            for(int num : bkt[i]){
                res.push_back(num);
            }
        }

        return res;




    }
};
