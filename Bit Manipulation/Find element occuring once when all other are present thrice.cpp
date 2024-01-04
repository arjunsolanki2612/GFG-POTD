/*
Ques: Find element occurring once when all others are present thrice
Link:https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
Company: Google
Medium

Given an array of integers arr[] of length N, every element appears thrice except for one which occurs once.
Find that element that occurs once.

Example 1:
Input:
N = 4
arr[] = {1, 10, 1, 1}
Output:
10
Explanation:
10 occurs once in the array while the other
element 1 occurs thrice.
*/

//Brute force
//User function Template for C++
// TC: O(n) SC:O(n)
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        
        for(auto &it:mp){
            int freq = it.second;
            if(freq==1){
                return it.first;
            }
        }
        return -1;
    }
};

// Optimized
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    //bitwise operator
    //TC: O(n), Sc: O(1)
    /*
    Logic: array is
    
    [51,51,51,37,38,38,38,57,57,57]
    
    number --------- bit representation
    51 ------------> 110011
    51 ------------> 110011
    51 ------------> 110011
    37 ------------> 100101
    38 ------------> 100110
    57 ------------> 111001
    38 ------------> 100110
    57 ------------> 111001
    38 ------------> 100110
    57 ------------> 111001
    
    ------------------------
total no. of set bits-->10-6-3-4-6-7, every number is a multiple of either 3n or 3n+1

the 3n number shows that the bit came 3n times means the number were present thrice times equally and 
3n+1 bit shows that there was a number which came only 1 time and contributed a set bit in 3n numbers

so the 3n+1 number will have a set bit and 3n number will have a non set bit in our answer which is 37

37 -> 100101 -> 10-6-3-4-6-8-7 like 10 is 3n+1 number 6 is 3n number similarly so on.
so we will find the number of set bit in 32 bit integer number if the number of set bits is 3n then we 
have to add that in our answer but if it is 3n+1 then we have to add it to our answer
    
    
    */
    int singleElement(int arr[] ,int N) {
        // code here
        int ans = 0;
        for(int i=0;i<32;i++){
            int count=0;
            for(int j=0;j<N;j++){
                if((arr[j] & (1<<i))!=0){
                    count++;
                }
            }
            if(count%3==1){
                ans = ans | (1<<i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
