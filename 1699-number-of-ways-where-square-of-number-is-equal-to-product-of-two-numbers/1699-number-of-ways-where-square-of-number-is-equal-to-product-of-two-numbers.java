class Solution {
    public int numTriplets(int[] nums1, int[] nums2) {
        int res = 0;
        res += solve(nums1,nums2);
        res += solve(nums2,nums1);
        return res;
    }

    private int solve(int nums1[] , int nums2[]){
        int n = nums1.length;
        int m = nums2.length;
        int res = 0;
        Map<Long,Integer> map = new HashMap<>();

        for(int i=0;i<n;i++){
            long sqr = (long)nums1[i] * (long)nums1[i];
            map.put(sqr,map.getOrDefault(sqr,0)+1);
        }

        for(int j=0;j<m-1;j++){
            for(int k=j+1;k<m;k++){
                long prod = (long)nums2[j] * (long)nums2[k];
                if(map.containsKey(prod))
                    res+=map.get(prod);
            }
        }
        
        return res;
    }
}