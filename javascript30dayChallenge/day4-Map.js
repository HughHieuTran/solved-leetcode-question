const map = function(arr, fn) {
    let result = [];
    for(let i =0; i<arr.length; i++){
        result.push(fn(arr[i],i))
    }
    return result;
};

const map2 = function(arr, fn) {
    for(let i =0; i<arr.length; i++){
        arr[i] = fn(arr[i],i);
    }
    return arr;
};