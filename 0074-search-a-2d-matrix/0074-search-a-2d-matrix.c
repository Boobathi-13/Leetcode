bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize; //row
    int n = *matrixColSize; //column
    int left = 0, right = m*n-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        int rowidx = mid/n; //row index
        int colidx = mid%n; //column index
        if(matrix[rowidx][colidx]==target) return true;
        else if(matrix[rowidx][colidx]<target) left = mid+1;
        else right = mid-1;
    }
    return false;
}