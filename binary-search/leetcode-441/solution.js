/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function(n) {
    return binarchSearch(n, 0, n);
};

function binarchSearch(number, startIndex, endIndex) {
    let middleIndex = parseInt((startIndex + endIndex) / 2);
    let middleBig = parseInt((middleIndex + 2)*(1 + middleIndex) / 2);
    let middleSmall = parseInt(middleIndex*(1 + middleIndex) / 2);
    if(middleBig >= number && middleSmall <= number) {
        if(middleBig == number) {
            return middleIndex + 1;
        }
        return middleIndex;
    } else {
        if(middleBig < number) {
            return binarchSearch(number, middleIndex + 1, endIndex);
        } else {
            return binarchSearch(number, startIndex, middleIndex - 1);
        }
    }
}