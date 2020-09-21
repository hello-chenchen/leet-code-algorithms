/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    let result = 0;
    for(let i = 0; i <= x; i++) {
        if(i * i <= x) {
            result = i;
        } else {
            break;
        }
    }

    return result;
};