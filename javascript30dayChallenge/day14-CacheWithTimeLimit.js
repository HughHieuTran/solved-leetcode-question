const TimeLimitedCache = function () {
    cache = new Map();  // Using Map so we don't need a size variable
    return {
        set: (key, value, duration) => {
            let found = cache.has(key);
            if (found) clearTimeout(cache.get(key).ref);
            cache.set(key, {
                value,
                ref: setTimeout(() => cache.delete(key), duration)
            });
            return found;
        },
        get: (key) => cache.has(key) ? cache.get(key).value : -1,
        count: () => cache.size
    }

};

