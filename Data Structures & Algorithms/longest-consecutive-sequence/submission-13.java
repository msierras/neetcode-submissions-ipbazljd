public class Solution {
    public int longestConsecutive(int[] nums) {
        // numSet being a HashSet will get rid of duplicates, unlike HashMap which uses key-value pairs, HashSet is just values 
        Set<Integer> numSet = new HashSet<>();
        // Populating numSet HashSet
        for (int num : nums) {
            numSet.add(num);
        }
        int longest = 0;

        for (int num : numSet) {
            // The moment we find a number (start num) which has no number smaller than it
            if (!numSet.contains(num - 1)) {
                // lenghth is 1 since we found start and that counts as 1 already
                int length = 1;
                // While there is a sequence 
                while (numSet.contains(num + length)) {
                    length++;   // Increase length
                }
                // We use Math.max() here is because we may find multiple sequences, and we want to keep track of the longest one seen so far.
                // This is useful because there may exist multiple numbers in nums that do not have a number smaller than it by one
                longest = Math.max(longest, length);
            }
        }
        return longest;
    }
}