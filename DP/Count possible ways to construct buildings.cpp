/*
Ques: Count possible ways to construct buildings
Company: PayU
Link: https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1
Medium

There is a road passing through a city with N plots on both sides of the road. Plots are arranged in a straight line on either side of the road. Determine the total number of ways to
construct buildings in these plots, ensuring that no two buildings are adjacent to each other. Specifically, buildings on opposite sides of the road cannot be adjacent.
Using * to represent a plot and || for the road, the arrangement for N = 3 can be visualized as follows: * * * || * * *.

Note: As the answer can be very large, print it mod 109+7.

Example 1:
Input: N = 1
Output: 4
Explanation: 
Possible ways for the arrangement are B||*, *||B, B||B, *||*
where B represents a building.
Example 2:

Input: N = 3
Output: 25
Explanation: 
Possible ways for one side are BSS, BSB, SSS, SBS,
SSB where B represents a building and S
represents an empty space. Pairing up with 
possibilities on the other side of the road,
total possible ways are 25.

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int building = 1;
	int space    = 0;
    int M = 1e9+7;
    int t[100001][2];
	int solve(int plot, int status){
	    if(plot == 0){
	        return 1;
	    }
	    if(t[plot][status]!=-1){
	        return t[plot][status];
	    }
	    if(status == building){
	        return t[plot][status]=solve(plot-1,space)%M;
	    }else{
	        return t[plot][status]=(solve(plot-1,building)%M  +  solve(plot-1,space)%M)%M;
	    }
	    
	    return -1;
	}
	int TotalWays(int N)
	{
	    // Code here
	    memset(t,-1,sizeof(t));
	    long long x = (solve(N-1,building)%M + solve(N-1,space)%M)%M;
	    return (x*x)%M;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends

// Bottom up 
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int building = 1;
	int space    = 0;
    int M = 1e9+7;

	int TotalWays(int N)
	{
	    // Code here
	    vector<vector<int>>t(N,vector<int>(2));
	    
	    for(int i=0;i<N;i++){
	        for(int j=0;j<2;j++){
	            // t[i][j]---> denotes the number of ways to construct building till ith plot having j status
	            // i --> denotes the current position of the plot or the index of the plot
	            // j --> denotes the status of the plot
	            
	            if(i==0){
	                t[i][j]=1;
	                continue;
	            }
	            
	            if(j==building){
	                t[i][j] = t[i-1][space]%M;
	            }else{
	                t[i][j] = (t[i-1][building]%M + t[i-1][space]%M)%M;
	            }
	        }
	    }
	    
	    long long x = (t[N-1][building]%M + t[N-1][space]%M)%M;
	    return (x*x)%M;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
