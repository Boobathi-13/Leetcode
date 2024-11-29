class Solution {
    public int unequalTriplets(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        for (int i = 0; i < n - 2; ++i)
            for (int j = i + 1; j < n - 1; ++j)
                if (nums[i] != nums[j])
                    for (int k = j + 1; k < n; ++k)
                        if (nums[j] != nums[k] && nums[k] != nums[i])
                            ++cnt;

        return cnt;
    }
}