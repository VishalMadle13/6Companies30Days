/*

688. Knight Probability in Chessboard
Medium
2.4K
332
Companies
On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.

*/


class Solution {
public: 
    double knightProbability(int N, int K, int r, int c){
        
        // no moves so probability 1
        if(K==0) return 1.0;
        
        // parent chess board
        vector<vector<double>> parentBoard(N,vector<double>(N,0.0));
        
        // child chess board
        vector<vector<double>> childBoard(N,vector<double>(N,0.0));
        
        // row and col offset for generating next move or child positions
        int rowoffset[] = {-2,-2,-1,-1,2,2,1,1};
        int coloffset[] = {1,-1,2,-2,1,-1,2,-2};
        
        int cx,cy;
        
        // initial position probability 1
        parentBoard[r][c] = 1.0;
        
        // Run K steps
        // Each step update the child position probability from parent position 
        // After each step assign child as parent board and create new child board
        for(int i=0;i<K;i++)
        {
            for(int p=0;p<N;p++)
            {
                for(int q=0;q<N;q++)
                { 
                    // calculate child position proabilty once from parent position probability
                    double moveProb = parentBoard[p][q]/8.0;
                    
                    // generate valid child positions
                    for(int w=0;w<8;w++)
                    {
                        cx = p + rowoffset[w];
                        cy = q + coloffset[w];

                        // update child position probability
                        if(cx>=0 && cx<N && cy>=0 && cy<N)
                            childBoard[cx][cy] += moveProb;
                    }                    
                }
            }
            
            parentBoard = childBoard;
            fill(childBoard.begin(),childBoard.end(),vector<double>(N,0.0));
        }
        

        
        double knightProb = 0.0;
        
        // Loop through parent board after K steps and sum up all probability
        for(int p=0;p<N;p++)
            for(int q=0;q<N;q++)
                   knightProb+=parentBoard[p][q];

        return knightProb;
    }
};