/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    let wordList = str.split(' ');
    if(wordList.length != pattern.length) {
        return false;
    }
    let hashMap = new Map();
    let result = true;
    for(let i = 0; i < pattern.length; i++) {
        if(undefined === hashMap.get(pattern[i])) {
            hashMap.set(pattern[i], wordList[i]);
        } else {
            if(wordList[i] !== hashMap.get(pattern[i])) {
                return false;
            }
        }
    }

    let setMap = new Set();
    hashMap.forEach((value) => {
        if(setMap.has(value)) {
            result = false;
        } else {
            setMap.add(value);
        }
    });

    return result;
};