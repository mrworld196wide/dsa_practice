//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int get (char c,char x[],int b[],int n){
        for(int i=0;i<n;i++){
            if(x[i]==c){
                return b[i];
            }
        }
        return int (c);
    }
    string maxSum(string w, char x[], int b[], int n){
        int cur_sum = 0;
        int maxi = 0;
        int start = 0;
        int end = 0;
        int s=0;
        for (int i=0;i<w.size() ; i++){
            cur_sum+= get(w[i],x,b,n);
            if(cur_sum> maxi){
                maxi= cur_sum;
                start= s;
                end = i;
            }
            if(cur_sum<0){
                cur_sum=0;
                s=i+1;
            }
        }
        return w.substr(start, end-start+1) ;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends