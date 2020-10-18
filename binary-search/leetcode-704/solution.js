/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    return binarchSearch(nums, target, 0, nums.length - 1);
};

function binarchSearch(number, target, left, right) {
    let middle = left;

    while(left <= right) {
        middle = parseInt((left + right) / 2);
        if(number[middle] > target) {
            right = middle - 1;
        }else if(number[middle] < target){
            left = middle + 1;
        }else {
            return middle;
        }
    }

    return number[middle] == target ? middle : -1;
}