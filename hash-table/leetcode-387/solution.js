/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    let hashMap = new Map();
    for(let i = 0; i < s.length; i++) {
        let temp = hashMap.get(s[i]);
        if(undefined === temp) {
            hashMap.set(s[i], 1);
        } else {
            hashMap.set(s[i], temp + 1);
        }
    }

    for(let i = 0; i < s.length; i++) {
        let temp = hashMap.get(s[i]);
        if(1 == temp) {
            return i;
        }
    }

    return -1;
};