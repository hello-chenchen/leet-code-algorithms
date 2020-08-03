import java.util.Map;
import java.util.HashMap;

class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> hashMap = new HashMap<Character, Integer>();
        for(int i = 0; i < s.length(); i++) {
            if(hashMap.containsKey(s.charAt(i))) {
                hashMap.put(s.charAt(i), hashMap.get(s.charAt(i))+1);
            } else {
                hashMap.put(s.charAt(i), 1);
            }
        }

        for(int i = 0; i < t.length(); i++) {
            if(hashMap.containsKey(t.charAt(i))) {
                hashMap.put(t.charAt(i), hashMap.get(t.charAt(i))-1);
            } else {
                return false;
            }
        }

        for(Map.Entry<Character, Integer> entry : hashMap.entrySet()){
            Integer mapValue = entry.getValue();
            if(0 != mapValue) {
                return false;
            }
        }

        return true;
    }
}