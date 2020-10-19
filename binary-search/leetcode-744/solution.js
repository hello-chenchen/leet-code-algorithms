/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function(letters, target) {
    return binarchSearch(letters, target, 0, letters.length - 1);
};

function binarchSearch(letters, target, left, right) {
    let middle = left;

    while(left <= right) {
        middle = parseInt((left + right) / 2);
        if(letters[middle] > target) {
            right = middle - 1;
        } else if(letters[middle] < target) {
            left = middle + 1;
        } else {
            console.log(middle);
            if(middle == 0) {
                return letters[1];
            } else if(middle == letters.length - 1) {
                return letters[0];
            } else {
                if(letters[middle + 1] == target) {
                    left = middle + 1;
                } else {
                    return letters[middle + 1];
                }
            }
        }
    }

    return left == letters.length ? letters[0] : letters[left];
}