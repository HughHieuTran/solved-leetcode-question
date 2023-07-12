
var timeLimit = function (fn, t) {
    return new Promise((resolve, reject) => {
        const run = setTimeout(() => reject('time exceeded'), t);
        fn(...args)
            .then((res) => resolve(res))
            .catch(err => reject(err))
            .finally(() => clearTimeout(run))
    })
};


var timeLimit2 = function (fn, t) {
    return async function (...args) {
        const oriFn = fn(...args);
        const timeoutfn = new Promise((_, reject) => {
            setTimeout(() => { reject('Time Limit Exceeded') }, t)
        })

        return Promise.race([oriFn, timeoutfn]);
    }
};
