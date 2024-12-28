bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize; //row
    int n = *matrixColSize; //column
    int rowidx = m-1; //leftbottom approach
    int colidx = 0;
    while(rowidx>=0 && colidx<n){
        if(matrix[rowidx][colidx] == target) return true;
        else if(matrix[rowidx][colidx] < target) colidx++;
        else rowidx--;
    }
    return false;
}