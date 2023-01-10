//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    bool isSafe(int row, int col, int board[N][N], int val) {
    
        for(int i = 0; i < N; i++) {
            //row check
            if(board[row][i] == val)
                return false;
            
            //col check
            if(board[i][col] == val)
                return false;
            
            //3*3 matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false;
        }
        return true;
    }
    
    bool solve(int board[N][N]) {
        
        for(int row = 0; row < N; row++) {
            for(int col = 0; col < N; col++) {
                //cell empty
                if(board[row][col] == 0) {
                    for(int val = 1; val <= 9; val++) {
                        if(isSafe(row, col, board, val)) {
                            board[row][col] = val;
                            //recursive call
                            bool furtherSolutionPossible = solve(board);
                            if(furtherSolutionPossible)
                                return true;
                            else
                                board[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
        
    
    
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends