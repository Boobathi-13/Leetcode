class Solution {
    public boolean findSubarrays(int[] nums) {
        int n = nums.length;
        int count = 0;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[j] + nums[j + 1] == nums[i] + nums[i + 1]) {
                    count++;
                }
            }
        }
        return count >= 1;
    }
}

//O(n^2)
//O(1)