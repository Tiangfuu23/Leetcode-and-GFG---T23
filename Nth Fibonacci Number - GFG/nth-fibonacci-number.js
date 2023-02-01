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

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for(;i<t;i++)
    {
        let n = parseInt(readLine());
        let obj = new Solution();
        console.log(obj.nthFibonacci(n));
        
    }
}

// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number} n
 * @returns {number}
*/
const mod = 1000000007;
class Solution {
    nthFibonacci(n)
    {
        const mod = 1000000007;
        const fibo = new Array(n+1);
        fibo[1] = fibo[2] = 1;
        for(let i = 3; i<=n; i++){
            const f1 = fibo[i-1]%mod;
            const f2 = fibo[i-2]%mod;
            fibo[i] = f1+f2;
        }
        return fibo[n]%mod;
    }
}