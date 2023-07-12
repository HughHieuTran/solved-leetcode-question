
function memoize0(fn) {
    let memory = {};
    return function (...args) {
        if (memory[args.join()] != null) {
            return memory[args.join()]
        } else {
            return (memory[args.join()] = fn(...args))
        }
    }
}

function memoize(fn) {
    let memory = {};
    return function (...args) {
        return memory[args.join()] != null ? memory[args.join()] :
            (memory[args.join()] = fn(...args))
    }
}