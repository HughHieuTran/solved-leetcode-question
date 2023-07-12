const toJsonString = (object) => {
    if (object === null || object === undefined) {
        return String(object);
    }
    if (Array.isArray(object)) {
        const values = object.map((obj) => JSON.stringify(obj));
        return `[${values.join(",")}]`
    }
    if (typeof (object) === "object") {
        const key = Object.keys(object);
        const keyValuePair = object.map(obj => `"${key}":${obj[key]}`)
        return `[${keyValuePair.join(",")}]`
    }
    if (typeof (object) === "string") {
        return `"${String(object)}"`;
    }
    return String(object);
}