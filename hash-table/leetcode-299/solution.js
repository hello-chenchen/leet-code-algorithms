/**
 * @param {string} secret
 * @param {string} guess
 * @return {string}
 */
var getHint = function(secret, guess) {
    let bulls = 0;
    let cows = 0;

    let setMap = new Map();
    let setTemp = new Map();
    for(let i = 0; i < secret.length; i++) {
        if(guess[i] === secret[i]) {
            bulls++;
        } else {
            let temp = setMap.get(secret[i]);
            if(undefined === temp) {
                setMap.set(secret[i], 0);
            } else {
                setMap.set(secret[i], temp + 1);
            }

            let temp = setTemp.get(guess[i]);
            if(undefined === setTemp.get(guess[i])) {
                setTemp.set(guess[i], 0);
            } else {
                setTemp.set(guess[i], temp + 1);
            }
        }
    }

    setTemp.forEach((value, key) => {
        if(setMap.has(key)) {
            cows += setTemp.get()
        }
    });

    return bulls + 'A' + cows + 'B';
};