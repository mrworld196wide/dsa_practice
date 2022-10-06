//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string lexicographicallySmallest(string S, int k) {
        // Correct the value of k
        int n= S.size();
        int N=n;
        while(N%2==0)
        {
            N>>=1;
        }
        if(N<=1) k>>=1;
        else k<<=1;
        
        // lexicographically smallest string
        if(k>=n) return "-1";
        
        string ans;
        int i=0;
        while(i<n and k>0)
        {
            if(ans.empty()) ans+=S[i++];
            else{
                if(ans.back()>S[i])
                {
                    ans.pop_back();
                    k--;
                }
                else{
                    ans+=S[i++];
                }
            }
        }
        while(k>0)
        {
            ans.pop_back();
            k--;
        }
        while(i<n)
        ans+=S[i++];
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int k;
        cin >> S >> k;
        Solution ob;
        cout << ob.lexicographicallySmallest(S, k) << endl;
    }
    return 0;
}

// } Driver Code Ends