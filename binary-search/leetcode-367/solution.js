/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    return binarySearch(num, 0, num);
};

function binarySearch(number, startIndex, endIndex) {
    let middleIndex = parseInt((startIndex + endIndex) / 2);
    if(middleIndex == startIndex) {
        if(startIndex * startIndex == number || endIndex * endIndex == number) {
            return true;
        }
        return false;
    }

    if(middleIndex * middleIndex > number) {
        return binarySearch(number, startIndex, middleIndex);
    } else if(middleIndex * middleIndex < number) {
        return binarySearch(number, middleIndex, endIndex);
    }else {
        return true;
    }
}