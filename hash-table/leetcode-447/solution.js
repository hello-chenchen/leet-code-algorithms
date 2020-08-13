/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfBoomerangs = function(points) {

    let res = 0;
    for(let i = 0; i < points.length; i++){
        let map = new Map();
        for(let j = 0; j < points.length; j++){
            if(j !== i){
                let distance = dis(points[i], points[j]);
                let temp = map.get(distance);
                if(undefined == temp){
                    map.set(distance, 1)
                }else{
                    map.set(distance, temp + 1);
                }
            }
        }
        map.forEach((count) => res += count * (count - 1));
    }
    return res;
};

function dis(x, y){
    return (y[1] - x[1])* (y[1] - x[1]) + (y[0] - x[0]) * (y[0] - x[0]);
}