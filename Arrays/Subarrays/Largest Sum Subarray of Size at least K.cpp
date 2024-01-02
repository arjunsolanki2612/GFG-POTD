/*
Largest Sum Subarray of Size at least K
https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1
Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input : 
n = 4
a[] = {1, -2, 2, -3}
k = 2
Output : 
1
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, -2, 2}
Example 2:
Input :
n = 6 
a[] = {1, 1, 1, 1, 1, 1}
k = 2
Output : 
6
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, 1, 1, 1, 1, 1}

*/

// } Driver Code Ends
class Solution{
    public:  
    typedef long long ll;
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        ll ans = INT_MIN;
        vector<ll>maxSumTill_i_idx(n);
        int csum = a[0];
        maxSumTill_i_idx[0]=a[0];
        //Kadanes algorithm
        for(int i=1;i<n;i++){
            if(csum>0){
                csum+=a[i];
            }else{
                csum=a[i];
            }
            
            maxSumTill_i_idx[i]=csum;
        }
        
        ll exactK = 0;
        for(int i=0;i<k;i++){
            exactK+=a[i];
        }
        if(exactK>ans){
            ans=exactK;
        }
        
        for(int i=k;i<n;i++){
            exactK = exactK + a[i] - a[i-k];
            
            if(exactK>ans){
                ans=exactK;
            }
            
            int maxTillatleastK = exactK + maxSumTill_i_idx[i-k];
            if(maxTillatleastK>ans){
                ans=maxTillatleastK;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
