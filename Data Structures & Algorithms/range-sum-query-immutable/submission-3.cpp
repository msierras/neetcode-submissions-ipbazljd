class NumArray {
private:
    // int vector that will hold our prefix
    vector<int> prefix;

public:
    // Doing the prefix work in the constructor so when we want to do lookups the prefix work is already done
    NumArray(const vector<int>& nums) {
        // Adding the +1 since we're including the 0 at the 0th index
        prefix = vector<int>(nums.size() +1);
        prefix[0] = 0;

        // Populating prefix vector
        for (int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }


    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

    /*
    The +1 size and the prefix[0] = 0 trick are what make the formula prefix[right+1] - prefix[left] work uniformly for all ranges, including those starting at index 0, 
    without any special-case if statements.

    Why prefix[0] = 0 is Needed:
        The formula prefix[right + 1] - prefix[left] works by saying: "Take the total sum up to right, then subtract everything that came before left."
        prefix[left] represents "everything before index left". So when left = 0, you're asking: "What came before index 0?"
        The answer is nothing, which numerically is 0. Without explicitly storing that, you'd have no value to subtract.                                                                                                                                                          
    
    Why prefix[right + 1] is Needed:
        Because of the +1 size shift, prefix[i] means "sum of everything strictly before index i", not "sum including index i". So to include nums[right] in your answer, 
        you need to look one step ahead at prefix[right + 1].

    */
    
};