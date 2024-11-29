class Solution {
    public int findValidSplit(int[] nums) {
        // prime factor freq
        // check left and right
        int n = nums.length;
        Map<Integer, Integer> totalPrimeMap = new HashMap<>();
        Map<Integer, Integer>[] primeMaps = new HashMap[nums.length];
        for (int i = 0; i < n; i++) {
            primeMaps[i] = new HashMap<>();
        }
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            compute(num, primeMaps[i], totalPrimeMap);
        }
        

        
        Map<Integer, Integer> primeMapPtr = new HashMap<>();
        for (int i = 0; i < n - 1; i++) {
            // System.out.println("i : " + i);
            if (ok(primeMapPtr, primeMaps[i], totalPrimeMap)) return i;
        }
        return -1;
    }
    
    private void compute(int x,  Map<Integer, Integer> primeMap, Map<Integer, Integer> totalPrimeMap) {
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                int freq = 0;
                while (x % i == 0) {
                    freq++;
                    x /= i;
                }
                primeMap.put(i, primeMap.getOrDefault(i, 0) + freq);
                totalPrimeMap.put(i, totalPrimeMap.getOrDefault(i, 0) + freq);
            }
        }
        
        if (x > 1) {
            primeMap.put(x, primeMap.getOrDefault(x, 0) + 1);
            totalPrimeMap.put(x, totalPrimeMap.getOrDefault(x, 0) + 1);
        }
    }
    
    private boolean ok(Map<Integer, Integer> primeMapPtr, Map<Integer, Integer> currPrimeMap, Map<Integer, Integer> totalPrimeMap) {
        for (int p : currPrimeMap.keySet()) {
            primeMapPtr.put(p, primeMapPtr.getOrDefault(p, 0) + currPrimeMap.get(p));
        }
        
        // check
        for (int p : primeMapPtr.keySet()) {
            if (primeMapPtr.get(p) < totalPrimeMap.get(p)) return false;
        }
        return true;
        
        
    }
}