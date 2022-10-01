//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m=grid[0].size();
        set<vector<pair<int,int>>>islands;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    vector<pair<int,int>>island;
                    dfs(i, j, i, j, n, m, grid, island);
                    islands.insert(island);
                }
            }
        }
        return islands.size();
    }
    void dfs(int x, int y, int x0, int y0, int n, int m, vector<vector<int>>&grid, vector<pair<int,int>>&island)
    {
        if(x>=n or x<0 or y>=m or y<0) return;
        
        grid[x][y]=0;
        island.push_back({x-x0, y-y0});
        
        // left
        if(x-1>=0 and grid[x-1][y])
        dfs(x-1, y, x0, y0, n, m, grid, island);
        // right
        if(x+1<n and grid[x+1][y])
        dfs(x+1, y, x0, y0, n, m, grid, island);
        // top
        if(y-1>=0 and grid[x][y-1])
        dfs(x, y-1, x0, y0, n, m, grid, island);
        // bottom
        if(y+1<=m and grid[x][y+1])
        dfs(x, y+1, x0, y0, n, m, grid, island);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends