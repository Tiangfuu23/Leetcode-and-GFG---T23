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
        let arr = new Array(n);
        let input_ar1 = readLine().split(' ').map(x=>parseInt(x));
        for(let i=0;i<n;i++)
            arr[i] = input_ar1[i];
        let obj = new Solution();
        if(obj.findTriplets(arr, n)){
            console.log("1");
        }
        else{
            console.log("0");
        }
        
    }
}
// } Driver Code Ends


//User function Template for javascript

/**
 * @param {number[]} arr
 * @param {number} n
 * @returns {boolean}
*/
[-65,-21,5,8,60,93]
class Solution {
    //Function to find triplets with zero sum.
    findTriplets(arr, n)
    {
        //your code here
        arr.sort((a,b) => a-b);
        for(let i = 0; i<n; i++){
            const curr_number = arr[i];
            if(curr_number > 0) return false;
            let [l,r] = [i+1,n-1];
            while(l<r){
                if(arr[l] + arr[r] > -curr_number) r--;
                else if(arr[l] + arr[r] < -curr_number ) l++;
                else return true;
            }
        }
        return false;
    }
}