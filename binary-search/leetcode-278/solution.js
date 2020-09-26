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
    let middleVersion = parseInt((start + end) / 2);
    if(isBadVersion(middleVersion - 1) != isBadVersion(middleVersion)) {
        return middleVersion;
    } else {
        if(true == isBadVersion(middleVersion)) {
            return badVersion(isBadVersion, start, middleVersion);
        } else {
            return badVersion(isBadVersion, middleVersion + 1, end);
        }
    }
}