public class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // Find the common prefix of binary representations of left and right
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
         
    }
}