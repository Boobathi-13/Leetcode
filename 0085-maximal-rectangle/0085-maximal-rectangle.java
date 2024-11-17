class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int[] heights = new int[n];
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            ans = Math.max(ans, largestRectInHistogram(heights));
        }
        return ans;
    }
    
    private int largestRectInHistogram(int[] heights) {
        // Monotonic Stack Approach
        Deque<Integer> stack = new ArrayDeque<>();
        int n = heights.length;
        int ans = 0;
        stack.offerFirst(-1);
        for (int i = 0; i < n; i++) {
            while (stack.peekFirst() != -1 && heights[stack.peekFirst()] > heights[i]) {
                int ind = stack.pollFirst();
                ans = Math.max(ans, heights[ind] * (i - stack.peekFirst() - 1));
            }
            stack.offerFirst(i);
        }
        while (stack.peekFirst() != -1) {
            int ind = stack.pollFirst();
            ans = Math.max(ans, heights[ind] * (n - stack.peekFirst() - 1));
        }
        return ans;
    }
}