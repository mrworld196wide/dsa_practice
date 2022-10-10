//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {

        vector<int>par(m*n,-1);
        vector<int>ans;

        for(auto op:operators){
            if(par[op[0]*m+op[1]]==-1){
                par[op[0]*m+op[1]]=op[0]*m+op[1];
                uni(op,par,n,m);
            }

            unordered_set<int>st;
            for(auto i:par){
                if(i!=-1)
                    st.insert(find(i,par));
            }
            ans.push_back(st.size());
        }
        return ans;
    }

    int uni(vector<int>op,vector<int>&par,int n,int m){
        int i=op[0],j=op[1];
        vector<pair<int,int>>dr={{0,-1},{-1,0},{0,1},{1,0}};
        auto parA=find(i*m+j,par);
        for(auto r:dr){
            int x=i+r.first,y=j+r.second;
            if(x<0 || x>=n || y<0 || y>=m || par[x*m+y]==-1)continue;
            int parB=find(x*m+y,par);
            par[parB]=parA;

        }

    }

    int find(int num,vector<int>&par){
        int cur=num;
        while(cur!=par[cur]){
            par[cur]=par[par[cur]];
            cur=par[cur];
        }
        return cur;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends