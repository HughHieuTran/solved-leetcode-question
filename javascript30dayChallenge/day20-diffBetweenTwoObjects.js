
function objDiff(o1, o2) {
    //both primitives and diff -> diff
    // one is obj and one isnt -> diff
    //one is array and one is obj -> diff
    // both is arr, or both are obj -> recursion


    if (!isObject(o1) && !isObject(o2)) { // both primitives
        return o1 === o2 ? {} : [o1, o2]
    }
    if (!isObject(o1) || !isObject(o2)) { // one obj
        return [o1, o2];
    }
    if (Array.isArray(o1) !== Array.isArray(o2)) {
        return [o1, o2];
    }
    const diff = {};

    for (const key in o1) {
        if (o2.hasOwnProperty(key)) {
            const res = objDiff(o1[key], o2[key])
            if (Object.keys(res).length > 0) {
                diff[key] = res;
            }
        }
    }

    return diff;


    function isObject(obj) {
        return obj !== null && typeof (obj) === "object";
    }

}