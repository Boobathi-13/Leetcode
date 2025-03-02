import java.util.Arrays;

class Solution {
    public int bestRotation(int[] nums) {
        int n = nums.length;
        int[] change = new int[n]; // differential array to track score changes
        
        // Populate the differential array based on conditions
        for (int i = 0; i < n; i++) {
            int left = (i + 1) % n;
            int right = (i - nums[i] + n + 1) % n;
            change[left] += 1;
            change[right] -= 1;
            if (left > right) {
                change[0] += 1;
            }
        }
        
        // Calculate the maximum score using the change array
        int maxScore = 0;
        int score = 0;
        int bestK = 0;
        
        for (int k = 0; k < n; k++) {
            score += change[k];
            if (score > maxScore) {
                maxScore = score;
                bestK = k;
            }
        }
        
        return bestK;
    }
}