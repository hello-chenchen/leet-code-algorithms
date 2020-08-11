/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let hashMap1 = new Set();
    for(let i = 0; i < nums1.length; i++) {
        hashMap1.add(nums1[i]);
    }

    let hashMap2 = new Set();
    for(let i = 0; i < nums2.length; i++) {
        hashMap2.add(nums2[i]);
    }

    var result = [];
    hashMap1.forEach((value) => {
        if(hashMap2.has(value)) {
            result.push(value);
        }
    });

    return result;
};