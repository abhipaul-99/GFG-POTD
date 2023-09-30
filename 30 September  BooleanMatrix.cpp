class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        vector<vector<int>> v;
        queue<pair<int,int>> q;
        unordered_map<int,bool> mp1;
        unordered_map<int,bool> mp2;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        
        while(q.size()>0){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(mp1[row]!= true){
                for(int j=0;j<m;j++){
                    matrix[row][j]=1;
                }
            }
            
            if(mp2[col]!= true){
                for(int i=0;i<n;i++){
                    matrix[i][col]=1;
                }
            }
            mp1[row] = true;
            mp2[col] = true;
        }
    }
};

/* Code Explanation:
1. It initializes a queue q to perform BFS traversal and two unordered maps mp1 and mp2 to keep track of rows and columns that have already been updated.
2. It determines the number of rows n and columns m in the input matrix.
3. It iterates through the entire input matrix to find cells with the value 1 and adds their positions to the queue q.
4. It enters a while loop that continues until the queue q is empty. Inside the loop, it processes each cell (row, col) that has a 1.
5. For each cell with a 1, it checks whether the row row has already been updated. If not, it updates all cells in that row to 1. Similarly, it checks whether the column col has already been updated. If not, it updates all cells in that column to 1.
6. It marks the row row and column col as updated in the mp1 and mp2 unordered maps, respectively.
7. The while loop continues until all cells with a value of 1 have been processed.
*/
