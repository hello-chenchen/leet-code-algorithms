/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let hashMap = new Map();
    for(let i = 0; i < s.length; i++) {
        let temp = hashMap.get(s[i]);
        if(undefined == temp) {
            hashMap.set(s[i], 1);
        } else {
            hashMap.set(s[i], temp + 1);
        }
    }

    for(let i = 0; i < t.length; i++) {
        let temp = hashMap.get(t[i]);
        if(undefined == temp || 0 == temp) {
            return t[i];
        } else {
            hashMap.set(t[i], temp - 1);
        }
    }
};