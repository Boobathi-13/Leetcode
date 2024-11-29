class Solution {
    public long beautifulSubarrays(int[] nums) {
        int n=nums.length;
        long ans = 0;
        int b[] = new int[n];
        int m=0;
        HashMap<Integer,Integer> nm = new HashMap<>();
        b[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            b[i] = b[i - 1] ^ nums[i];
        }
        for(int i = 0; i < n; i++)
        {
            int xx = m^b[i];
            ans=ans+(!nm.containsKey(xx) ? 0 : ((long)nm.get(xx)));
            if(b[i] == m)
            {
                ans++;
            }
            if(nm.containsKey(b[i]))
            {
                nm.put(b[i], nm.get(b[i]) + 1);
            }
            else
            {
                nm.put(b[i], 1);
            }
        }
        return ans;

    }
}