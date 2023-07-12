var createCounter = (init) => {
    let current = init;
    return {
        increment: () => ++current,
        reset: () => (current = init),
        decrement: () => --current,
    }
}

const counter = createCounter(5);
console.log(counter.increment());
console.log(counter.increment());
console.log(counter.decrement());
console.log(counter.reset());
console.log(counter.decrement());