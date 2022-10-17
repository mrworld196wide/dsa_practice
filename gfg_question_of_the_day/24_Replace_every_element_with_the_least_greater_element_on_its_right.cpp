//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    struct Tnode{
        struct Tnode *left,*right;
        int val;
        Tnode(int v)
        {
            left = NULL;
            right = NULL;
            val = v;
        }
    };
    int temp = -1;
    int insert(Tnode *root,int ele)
    {
        if(ele < root->val)
        {
            temp = root->val;
            if(root->left==NULL)
            {
                root->left = new Tnode(ele);
                return temp;
            }
            else
            return insert(root->left,ele);
        }
        else
        {
            if(root->right==NULL)
            {
                root->right = new Tnode(ele);
                return temp;
            }
            else
            return insert(root->right,ele);
        }

    }
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
       vector<int> ans(n);
        Tnode *root = new Tnode(arr[n-1]);
        ans[n-1] = -1;
        //int ng=-1;
        for(int i=n-2;i>=0;i--)
        {
            temp = -1;
            ans[i] =insert(root,arr[i]);
        }
        return ans; 
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends