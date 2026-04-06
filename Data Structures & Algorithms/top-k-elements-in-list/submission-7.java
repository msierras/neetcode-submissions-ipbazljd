public class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // HashMap that will contain the num of times each integer apears in array nums 
        Map<Integer, Integer> count = new HashMap<>();
        // List array where each index represents how many times an integer appeared, i.e., at index 2 it contains integers that appeared twice in nums
        // We add 1 to nums.length so we go from range of 0 - length-1 to range of 0 - length
        List<Integer>[] freq = new List[nums.length + 1];

        // Populating the freq list with empty ArrayLists at each index 
        for (int i = 0; i < freq.length; i++) {
            freq[i] = new ArrayList<>();
        }

        // Populating count with the number of occurrences for each integer 
        for (int n : nums) {
            count.put(n, count.getOrDefault(n, 0) + 1);
        }

        // Populating the ArrayLists of freq array  
        // Using Map.Entry<T, T> var since we want both the key and value
        // Usage of .entrySet() on the HashMap we want to use is also needed
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            freq[entry.getValue()].add(entry.getKey());
        }

        // Creating array that will hold the top k with the highest occurrences
        int[] res = new int[k];
        int index = 0;
        // We do freq.length - 1 to start with the arraylist with the highest num of occurrences
        // i > 0 since we dont want integers with 0 occurrences
        // index represents how many elements we've already added to res 
        for (int i = freq.length - 1; i > 0 && index < k; i--) {    // outer array gets us to the ArrayList of index i
            for (int n : freq[i]) { // inner loop gets us to the integer(s) in each ArrayList 
                res[index] = n;
                index++;
                if (index == k) {
                    return res;
                }
            }
        }
        return res;
    }
}