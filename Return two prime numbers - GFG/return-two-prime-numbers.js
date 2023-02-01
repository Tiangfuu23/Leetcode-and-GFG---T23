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
        let obj = new Solution();
        let res = obj.primeDivision(n);
        printList(res,res.length);
    }
}// } Driver Code Ends


// } Driver Code Ends


//User function Template for javascript



/**
 * @param {number} n
 * @returns {number[]}
*/
function sieve(isPrime, n){
        isPrime[0] = isPrime[1] = false;
        for(let i = 2; i*i <= n; i++){
            if(!isPrime[i]) continue;
            for(let j = i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
class Solution{
    primeDivision(n){
        //code here
    const isPrime = new Array(n+1).fill(true);
    sieve(isPrime,n);
    let l = 2, r = n-2;
    while(l<=r){
        if(!isPrime[l]) l++;
        else if(!isPrime[r]) r--;
        else if(l+r > n) r--;
        else if(l+r < n) l++;
        else{
            return [l,r];
        }
    }
    }
}



