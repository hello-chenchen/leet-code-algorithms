/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(arr) {
    return binarySearch(arr, 0, arr.length - 1);
};

function binarySearch(arr, left, right) {
    let top = arr[left];
    let middle = left;
    while(left < right && (right - left) >= 2) {
        let middle = parseInt((left + right) / 2);
        if(arr[middle] > arr[middle - 1] && arr[middle] < arr[middle + 1]) {
            left = middle;
        } else if(arr[middle] > arr[middle + 1] && arr[middle] < arr[middle - 1]) {
            right = middle;
        } else {
            return middle;
        }
    }
}