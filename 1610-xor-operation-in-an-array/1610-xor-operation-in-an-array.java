class Solution {
    public int xorOperation(int n, int start) {
        int[] array = new int[n];
        int res = 0 ;
        for(int i = 0 ; i < n ; i++){
            array[i] = start + 2 * i;
            res = res ^ array[i];
        } 
        return res;
    }

}