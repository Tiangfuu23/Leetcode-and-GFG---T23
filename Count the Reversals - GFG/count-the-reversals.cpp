//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int countRev (string s)
{
    if(s.size()%2!=0) return -1;
    // string str; cin >> str;
	stack<char> st;
//	int ans = 0;
	for(auto c : s){
		if(c=='}'){
			if(!st.empty() && st.top() == '{') st.pop();
			else st.push(c);
		}else{
			st.push(c);
		}
	}
	int cntOpen = 0, cntClose = 0;
	while(!st.empty()){
		char c = st.top(); st.pop();
		if(c=='{') cntOpen++;
		else cntClose++;
	}
	return cntOpen/2 + cntClose/2 + 2*(cntOpen%2==1 ? 1: 0);
}