class Solution {
    public int[] fullBloomFlowers(int[][] flowers, int[] persons) {
        
        int m = flowers.length;
        int n = persons.length;

        int[] result = new int[n];

        int[][] personWithIndex = new int[n][2];
        for(int i = 0; i < n; i++) personWithIndex[i] = new int[]{persons[i], i};

        Arrays.sort(personWithIndex, (a, b) -> Integer.compare(a[0], b[0]));

        Arrays.sort(flowers, (a, b) -> Integer.compare(a[0], b[0]));

        PriorityQueue<Integer> minHeapEndTime = new PriorityQueue<>();

        int flowerIndex = 0;

        for(int[] person : personWithIndex){

            int personTime = person[0];
            int personActualIndex = person[1];

            while(flowerIndex < m && flowers[flowerIndex][0] <= personTime) {
                minHeapEndTime.add(flowers[flowerIndex][1]);
                flowerIndex++;
            }

            while(!minHeapEndTime.isEmpty() && minHeapEndTime.peek() < personTime) {
                minHeapEndTime.poll();
            }

            result[personActualIndex] = minHeapEndTime.size();
        }

        return result;
    }
}