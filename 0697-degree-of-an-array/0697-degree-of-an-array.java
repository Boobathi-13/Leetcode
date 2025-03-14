class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> start_idx = new HashMap(),
            last_idx = new HashMap(), count = new HashMap();

        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            if (start_idx.get(x) == null) {
                start_idx.put(x, i);
            }
            last_idx.put(x, i);
            count.put(x, count.getOrDefault(x, 0) + 1);
        }
        System.out.println(start_idx);
         System.out.println(last_idx);
          System.out.println(count);
        int ans = nums.length;
        int degree = Collections.max(count.values());
         System.out.println(degree);
        for (int x: count.keySet()) {
            if (count.get(x) == degree) {
                 System.out.println(x);
                ans = Math.min(ans, last_idx.get(x) - start_idx.get(x) + 1);
            }
        }
        return ans;
    }
}