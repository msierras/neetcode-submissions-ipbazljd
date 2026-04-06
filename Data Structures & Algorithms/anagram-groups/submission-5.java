public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // HashMap where the sorted string is the key and its value is the list of anagrams 
        Map<String, List<String>> res = new HashMap<>();

        // Iterate through each string in the string array strs 
        for (String s : strs) {
            
            // Create a character array and assign the string s which is converted to an array of characters 
            char[] charArray = s.toCharArray();
            
            // Sort the array of characters charArray
            Arrays.sort(charArray);
            
            // Create a String sortedS and assign charArray
            String sortedS = new String(charArray); // Can do new String(charArray) because charArray is an array of characters specifically 
            
            // If the key sortedS for hashmap res does not have a value then put a new ArrayList
            res.putIfAbsent(sortedS, new ArrayList<>());
            
            /// Add the original string to the list corresponding to its sorted key
            // .get(sortedS) gets the list stored at that key
            // .add() adds the new string to that list
            // NOTE: res.put(sortedS, s) will not work because the value for the HashMap res expects List<String> not just String! 
            res.get(sortedS).add(s);
        }

        // Return a new ArrayList with the list of anagrams 
        return new ArrayList<>(res.values());
    }
}