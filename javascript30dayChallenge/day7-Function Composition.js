var compose = function (functions) {
    return function (x) {
        let acc = x;
        for(let i =functions.length-1; i >=0 ; i--){
            acc = functions[i](acc);
        }
        return acc;
    }
};


var compose2 = function (functions) {
    return function (x) {
        return functions.reduceRight(
            (acc, fn) =>
                fn(acc)
            , x
        )
    }
};