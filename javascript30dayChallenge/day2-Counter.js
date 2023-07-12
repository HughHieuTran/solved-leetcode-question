
//long

let createCounter0 = (n) => {
    return () => n++;
}

// short

var createCounter = (n) => () => n++;

// use

 const counter = createCounter(10)
 counter() // 10
 counter() // 11
 counter() // 12