//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
string isDivisibleBy5(string bin);

int main(){
    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        cout << isDivisibleBy5(s) << endl;

    }

return 0;
}


// } Driver Code Ends


//User function Template for C++

char convert(string s){
    if(s=="00") return '0';
    else if(s=="01") return '1';
    else if(s=="10") return '2';
    return '3';
}

string isDivisibleBy5(string bin){
    if(bin.size() % 2 != 0) bin.insert(0,"0");
    string temp;
    for(int i = 0; i<bin.size(); i+=2){
        temp.push_back(convert(bin.substr(i,2)));
    }
    int sumEven = 0,sumOdd = 0;
    for(int i = 0; i<temp.size(); i++){
        if(i%2==0) sumEven += temp[i] -'0';
        else sumOdd += temp[i] - '0';
    }
    // return temp;
    if(abs(sumOdd-sumEven)%5 == 0){
        return "Yes";
    }
    return "No";
}