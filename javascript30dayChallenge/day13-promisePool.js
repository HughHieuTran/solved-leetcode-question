
var promisePool = (fns, n) => { //fns: function[],  n : max allow running
    return new Promise((resolve, reject) => {
        let i = 0;
        let running = 0;

        const callback = () => {
            if (i === fns.length && running === 0) {
                resolve();
            }
            while (i < fns.length && running < n) {
                fns[i++]().then(() => {
                    running--;
                    callback;
                })
                running++;
            }
        }

        callback()
    })
}