/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
    let result = 0;
    for(let i = 0; i < grid.length; i++) {
        result += binarySearch(grid[i], 0, grid[i].length - 1);
    }

    return result;
};

function binarySearch(array, left, right) {
    let length = right;
    let middle = left;
    while(left < right) {
        middle = parseInt((left + right) / 2);
        if(array[middle] >= 0) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    if(array[left] < 0) {
        return (length - left + 1);
    } else if(array[right] >= 0) {
        return 0;
    } else {
        return 1;
    }
}