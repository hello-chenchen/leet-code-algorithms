/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function(n) {
    return binarySearchNumber(1, n);
};

function binarySearchNumber(left, right) {
    let middle = left;

    while(left <= right) {
        middle = parseInt((left + right) / 2);
        if(guess(middle) == -1) {
            right = middle - 1;
        } else if(guess(middle) == 1) {
            left = middle + 1;
        }else {
            return middle;
        }
    }
}