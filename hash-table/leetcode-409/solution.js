/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    var hashMap = new Map();
    for(let i = 0; i < s.length; i++) {
        let temp = hashMap.get(s[i]);
        if(undefined == temp) {
            hashMap.set(s[i], 1);
        } else {
            hashMap.set(s[i], temp + 1);
        }
    }

    let result = [];
    let res = 0;
    let flag = 0;
    hashMap.forEach((value) => {
        if((value % 2) == 0) {
            res += value;
        } else {
            flag = 1;
            res += value - 1;
        }
    })

    return res + flag;
};