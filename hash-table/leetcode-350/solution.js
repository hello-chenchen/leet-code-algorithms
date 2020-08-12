/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    let hashMap = new Map();
    for(let i = 0; i < nums1.length; i++) {
        let temp = hashMap.get(nums1[i]);
        if(undefined === temp) {
            hashMap.set(nums1[i], 1);
        } else {
            hashMap.set(nums1[i], temp + 1);
        }
    }

    let result = [];
    for(let i = 0; i < nums2.length; i++) {
        let temp = hashMap.get(nums2[i]);
        if(undefined != temp && 0 != temp) {
            hashMap.set(nums2[i], temp - 1);
            result.push(nums2[i]);
        }
    }

    return result;
};