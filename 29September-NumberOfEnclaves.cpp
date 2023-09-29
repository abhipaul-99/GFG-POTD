// User function Template for C++
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; 
        int n = grid.size(); 
        int m = grid[0].size(); 
        int vis[n][m] = {0}; 
        // traverse boundary elements
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // first row, first col, last row, last col 
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    // if it is a land then store it in queue
                    if(grid[i][j] == 1) {
                        q.push({i, j}); 
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, +0, -1}; 
        
        while(!q.empty()) {
            int row = q.front().first; 
            int col = q.front().second; 
            q.pop(); 
            
            // traverses all 4 directions
            for(int i = 0;i<4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                // check for valid coordinates and for land cell
                if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
            
        }
        
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                // check for unvisited land cell
                if(grid[i][j] == 1 & vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt; 
    }
};

/* Code Explanation:
Here's a brief summary of how the code works:

1. It initializes a queue q for BFS traversal and gets the dimensions of the grid.
2. It initializes a 2D array vis to keep track of visited cells. Initially, all elements are set to 0.
3. The code then iterates through the boundary cells of the grid. If a land cell is found on the boundary, it is added to the queue q for traversal, and its status is marked as visited in the vis array.
4. Two arrays, delrow and delcol, are used to represent possible directions (up, right, down, left) to move from a cell during traversal.
5. The main BFS loop starts by dequeuing a cell from q and explores its neighbors in all four directions. If a neighbor is within the grid bounds, unvisited, and contains a land cell, it is enqueued for further traversal, and its status in the vis array is marked as visited.
6. After BFS traversal, the code counts the remaining unvisited land cells in the grid, which represent the enclaves.
7. The count of enclaves is returned as the final result.
*/
