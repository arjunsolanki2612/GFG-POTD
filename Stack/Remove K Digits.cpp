/*
Ques: Remove K Digits
Link: https://www.geeksforgeeks.org/problems/remove-k-digits/1
Medium
Microsoft

Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input:
S = "149811", K = 3
Output: 
111
Explanation: 
Remove the three digits 
4, 9, and 8 to form the new number 111
which is smallest.
Example 2:

Input:
S = "1002991", K = 3
Output: 
21
Explanation: 
Remove the three digits 1(leading
one), 9, and 9 to form the new number 21(Note
that the output must not contain leading
zeroes) which is the smallest.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int k) {
        stack<char> ch;
        for(auto it:S)
        {
            while(k and !ch.empty() and ch.top()>it)
            {
                ch.pop();
                k--;
            }
            
            if(ch.empty() and it=='0')
            continue;
        
            ch.push(it);
        }
        
       //k is not zero, 
        while(!ch.empty() and k)
        {
            ch.pop();
            k--;
        }
        
         //making ans string
        string ans="";
        while(!ch.empty())
        {
            ans+=ch.top();
            ch.pop();
        }
        
        if(ans.size()==0)
        return "0";
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
