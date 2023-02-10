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
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        let S = input_ar1[0];
        let D = input_ar1[1];
        let obj = new Solution();
        let res = obj.smallestNumber(S, D);
        console.log(res);
        
    }
}// } Driver Code Ends


// } Driver Code Ends


//User function Template for javascript


/**
 * @param {number} S
 * @param {number} D
 * @returns {string}
*/

class Solution{
    smallestNumber(s, d){
        if( (s===0 && d!==1) || (9*d < s) ) return -1;
        s--; // carry 1 
        const ans = new Array(d).fill(0);
        for(let i = ans.length-1; i>=0; i--){
            if(s>9){
                ans[i] = 9;
                s-=9;
            }else{
                ans[i] = s;
                s=0;
            }
        }
        ans[0] += 1; // because carry = 1
        let str = "";
        // ans.forEach((i)=>{
        //     str += toString(i);
        // })
        for(let i = 0; i<ans.length; i++) str += ans[i].toString(10);
        return str;
    }
}



