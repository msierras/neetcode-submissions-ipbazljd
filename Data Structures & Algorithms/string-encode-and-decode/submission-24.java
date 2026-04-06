public class Solution {

    public String encode(List<String> strs) {

        /* 
        Unlike the String class (which is immutable), StringBuilder allows modification of character sequences 
        without creating new objects, making it memory-efficient and faster for frequent string operations.
        */
        StringBuilder res = new StringBuilder();
        
        // Going from ["Hello", "World"] -> 5#Hello5#World with the loop below 
        for (String s : strs) {
            res.append(s.length()).append('#').append(s);
        }

        // Must convert StringBuilder object to a String object before returning 
        return res.toString();
    }


    public List<String> decode(String str) {
        // res will hold the decoded list of strings
        List<String> res = new ArrayList<>();

        int i = 0;
        while (i < str.length()) {
            
            // while loop will get us to the #
            int j = i;
            while (str.charAt(j) != '#') {
                j++;
            }
            
 
            // Extract the number before '#' which represents the length of the next word          5#Hello5#World
            int length = Integer.parseInt(str.substring(i, j));   //                                      ij
            i = j + 1; // Puts us at the first letter of the string
            j = i + length; // j will now be at the end of the string 
            res.add(str.substring(i, j)); // adding string to res                                  5#Hello5#World
            i = j;  // Setting i to j to continue loop                                                      i   j
        }
        return res;
    }
}