//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
         int b[100001]={0};
       for(int i=0;i<n;i++)
       {
           b[a[i]]++;
       }
       int  s=0;
       int x=1;
       for(int i=100000;i>=1;i--)
       {
           x=b[i];
           if(b[i]>0)
           {
               if(b[i-1]>0)
               {
                  if(b[i]>=b[i-1])
                  {
                      x=b[i];
                      b[i-1]=0;
                  }
                  else
                  {
                      x=b[i];
                      b[i-1]=b[i-1]-b[i];
                  }
               }
               s+=(i*x);
           }
       }
       
       return s;
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends