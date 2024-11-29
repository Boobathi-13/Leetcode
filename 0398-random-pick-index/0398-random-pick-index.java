class Solution {

    Map<Integer, ArrayList<Integer>> map = new HashMap<>();

    public Solution(int[] nums) {
        for (int i=0;i<nums.length;i++) {
            ArrayList<Integer> list = map.getOrDefault(nums[i], new ArrayList<>());
            map.put(nums[i], list);
            list.add(i);
        }
    }
    
    public int pick(int target) {
        ArrayList<Integer> list = map.get(target);
        int i = (int)(Math.random()*list.size());
        return list.get(i);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */