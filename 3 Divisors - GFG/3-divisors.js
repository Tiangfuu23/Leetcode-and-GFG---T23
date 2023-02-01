//{ Driver Code Starts
//Initial Template for javascript

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();
});

function readLine() {
    return inputString[currentLine++];
}

function printList(res,n){
    let s="";
    for(let i=0;i<n;i++){
        s+=res[i];
        s+=" ";
    }
    console.log(s);
}


function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let arr = new Array(n);
        for(let i=0;i<n;i++){
            arr[i] = parseInt(readLine());
        }
        let obj = new Solution();
        let res = obj.threeDivisors(arr, n);
        for(let i=0;i<res.length;i++){
            console.log(res[i]);
        }
        
    }
}// } Driver Code Ends



// } Driver Code Ends


//User function Template for javascript


/**
 * @param {number[]} query
 * @param {number} q
 * @returns {number[]}
*/
function isPrime(n){
    for(let i = 2; i*i<=n; i++){
        if(n%i===0) return false;
    }
    return Boolean(n>1);
}
class Solution{
    threeDivisors(query, q){
        //code here
    const res = [];
    for(let i = 0; i<q; i++){
        let n = query[i];
        let ans = 0; 
        for(let p = 2; p*p <= n; p++){
            if(isPrime(p)) ans++;
        }
        res.push(ans);
    }
    return res;
    }
}
