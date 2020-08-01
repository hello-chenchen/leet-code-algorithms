#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        map<int, int> hashMap;
        map<int, int>::iterator itr;
        for(int i = 0; i < s.length(); i++) {
            itr = hashMap.find(s[i]);
            if(hashMap.end() != itr) {
                itr->second++;
            } else {
                hashMap.insert(pair<int, int>(s[i], 1));
            }
        }

        for(int i = 0; i < t.length(); i++) {
            itr = hashMap.find(s[i]);
            if(hashMap.end() != itr) {
                itr->second--;
            } else {
                return false;
            }
        }

        for (itr = hashMap.begin(); itr != hashMap.end(); ++itr) {
            if(0 != itr->second) {
                return false;
            }
        }

        return true;
    }
};