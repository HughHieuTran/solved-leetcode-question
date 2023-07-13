var flat = function (arr, n) {
    if (n==0) return arr;
    let answer = [];
    for(let i =0;i<arr.length;i++){
        typeof(arr[i])=== "number"? answer.push(arr[i]) : answer.push(...flat(arr[i],n-1))
    }
    return answer;
 };