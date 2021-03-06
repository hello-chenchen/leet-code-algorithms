/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if(x <= 1) return x;
    return binarySearch(x, 0, x);
};

function binarySearch(x, start, end) {
    let middle = parseInt((start + end) / 2);
    if(middle > start && middle < end) {
        if(middle * middle > x) {
            return binarySearch(x, start, middle);
        } else {
            return binarySearch(x, middle, end);
        }
    } else {
        if(middle * middle > x) {
            return middle - 1;
        }
        return middle;
    }
}