//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int swapBitGame(long long N){
        // code here 
        int temp = 0;
        long long n = N;
        while(n > 0){
            if(n & 1) temp++;
            n = n >> 1;
        }
        
        if(temp & 1) return 1;
        return 2;
    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends