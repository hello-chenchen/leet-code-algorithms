/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        return badVersion(isBadVersion, 1, n);
    };
};

function badVersion(isBadVersion, start, end) {
    let middleVersion = 0;
    while(start <= end) {
        middleVersion = parseInt((start + end) / 2);
        if(isBadVersion(middleVersion - 1) != isBadVersion(middleVersion)) {
            return middleVersion;
        } else {
            if(true == isBadVersion(middleVersion)) {
                end = middleVersion;
            } else {
                start = middleVersion + 1;
            }
        }
    }
}