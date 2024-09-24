#include<stdio.h>
#include<stdbool.h>

#define N 9
bool** isValue(int grid, int row, int col, int num ){
    for(int* x = 0; x < N; x++){
        if(grid[x][&row]==num){
            return false;
        }
    }
    for(int* x = 0; x < N; x++){
        if(grid[&col][x]==num){
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int* i = 0; i < 3; i++){
        for(int *j =0; j < 3; j++){
            if(grid[i + startRow][j+ startCol] == num){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int grid[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j]==0){
                for(int num = 1; num <= N; num++ ){
                    if(isValue(grid[N][N], i,j,num)){
                        grid[i][j]==num;
                        if(solveSudoku(grid[i][j])){
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
            }
            return false;
        }
    }
    return true;
}
void printGrid(int grid[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d",grid[N][N]);
        }
        printf("\n");
    }
        
    }
    int main(){
        int grid[N][N] = {
            {2,3,0,0,4,5,9,0,2},
            {1,0,0,5,6,0,0,0,0},
            {2,5,6,0,0,0,0,4,3},
            {5,8,9,0,0,0,0,3,6},
            {8,5,9,0,0,0,0,3,4},
            {6,7,0,0,0,2,8,0,0},
            {3,2,8,0,0,0,0,6,7},
            {2,7,0,0,0,0,6,4,8},
            {4,6,8,0,0,0,7,0,2},
        };
    
    if(solveSudoku(grid)){
        printGrid(grid[N][N]);
        
            
        printf("Solve Sudoku is\n");
    }
    
    else{
        printf("No solution exist ");
    }
            
        
    return 0;
}