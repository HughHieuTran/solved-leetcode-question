var once = function(fn) {
    called= false;
   
    return function(...args){
        if(called) return undefined;
        called=true;
        return fn(...args);
    }
};