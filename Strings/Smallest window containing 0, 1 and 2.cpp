/*
QUES: Smallest window containing 0, 1 and 2
Link: https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1
Companies: Paytm

Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 and 2. 
If no such substring exists, then return -1.

Example 1:

Input:
S = 10212
Output:
3
Explanation:
The substring 102 is the smallest substring
that contains the characters 0, 1 and 2.

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int ans = INT_MAX;
        int seenZero = -1, seenOne = -1, seenTwo = -1;
        for(int i=0;i<S.length();i++){
            if(S[i]=='0'){
                seenZero = i;
            }else if(S[i]=='1'){
                seenOne = i;
            }else{
                seenTwo = i;
            }
            
            if(seenOne!=-1 && seenTwo!=-1 && seenZero!=-1){
                ans = min(ans, i - min({seenOne,seenTwo,seenZero}) + 1);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends

// little Modification in code
class Solution {
  public:
    int smallestSubstring(string S) {
        int ans = INT_MAX;
        int lastSeen[3] = {-1, -1, -1}; // array to store the last occurrence of each character
        for(int i = 0; i < S.length(); i++) {
            lastSeen[S[i] - '0'] = i; // update the last occurrence of the current character
            
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                ans = min(ans, i - min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
