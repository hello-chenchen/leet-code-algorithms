/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    let bulls = 0;
    let cows = 0;

    let hashMap = new Map();
    for(let i = 0; i < secret.length; i++) {
        let temp = hashMap.get(secret[i]);
        if(undefined === temp) {
            hashMap.set(secret[i], 1);
        } else {
            hashMap.set(secret[i], temp + 1);
        }
    }

    //for bulls
    var guessCopy = [];
    for(let i = 0; i < guess.length; i++) {
        if(secret[i] == guess[i]) {
            hashMap.set(secret[i], hashMap.get(secret[i]) - 1);
            bulls++;
        } else {
            guessCopy.push(guess[i]);
        }
    }

    //for cows
    for(let i = 0; i < guessCopy.length; i++) {
        let temp = hashMap.get(guessCopy[i]);
        if(undefined != temp && 0 != temp) {
            hashMap.set(guessCopy[i], temp - 1);
            cows++;
        }
    }

    return bulls + 'A' + cows + 'B';
};