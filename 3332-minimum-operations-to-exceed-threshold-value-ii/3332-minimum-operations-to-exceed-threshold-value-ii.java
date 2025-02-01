class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for(int num:nums) minHeap.offer(num);
        System.out.println(minHeap);
        int count = 0;
        while(minHeap.size() > 1 &&minHeap.peek() < k){
            int x = minHeap.poll();
            int y = minHeap.poll();
            int res = x*2 + y;
            minHeap.offer(res);
            count++;
        }
        return count;
    }
}