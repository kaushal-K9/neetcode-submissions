class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        
        //if we encounter water or run out of bounds
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) return;

        if (grid[i][j] == '0' || vis[i][j] == 1) return;
        
        //mark visited
        vis[i][j] = 1;

        //go to depths
        dfs(i + 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j - 1, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        //no of rows
        int m = grid.size();

        //no of columns
        int n = grid[0].size();

        int count = 0;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        //for dfs calls to be made for each node
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {

                    count += 1;

                    //aim of dfs is to mark all 
                    //connected nodes of an island
                    dfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};


//at node (i, j)

//keep going left (i, j + 1) 
//until 
// i < m  or j < n

//maintain a list of visited,
//and check
//vis[i][j] == 1? then explore ahead
//if vis[i][j] == 0, return early


//we start a dfs call from each unvisited node,
//and after completing all calls, we have one island

//we try to start dfs from each node by checking visited
//we only start from the non-zero node
//if (vis[i][j] == 0 && grid[i][j] == 1) dfs(i, j)