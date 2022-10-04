//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    const int M = 1e9+7;
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long>>dp(m, vector<long long>(n, 1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++)
                dp[i][j]=(dp[i][j-1]+dp[i-1][j])%M;
        }
        return dp[m-1][n-1];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends