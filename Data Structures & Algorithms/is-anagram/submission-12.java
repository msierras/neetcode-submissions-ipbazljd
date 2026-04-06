class Solution {
    public boolean isAnagram(String s, String t) {

        // If both strings aren't the same length then it's impossible for them to be anagrams 
        if(s.length() != t.length()){
            return false;
        }

        // HashMaps that will contain the count of the characters in each string
        HashMap<Character, Integer> sCount = new HashMap<Character, Integer>();
        HashMap<Character, Integer> tCount = new HashMap<Character, Integer>();

        for(int i = 0; i < s.length() ; i++){
            /* 
                MapName.getOrDefault(keyToSearchFor, valueToReturnIfKeyIsMissing)
                
                First argument: the key we are looking up in the map
                Second argument: the value to return if the key does not exist
                Returns the existing value for the key if present; otherwise returns the default value 
            */
            // If the character is not already in the map, initialize its count to 0. Then increment the count by 1.
            sCount.put( s.charAt(i), sCount.getOrDefault( s.charAt(i) , 0 ) + 1 );
            tCount.put( t.charAt(i), tCount.getOrDefault( t.charAt(i) , 0 ) + 1 );
        }

        // Does the count of each char in the HashMaps equal to each other?
        return sCount.equals(tCount);

    }
}
