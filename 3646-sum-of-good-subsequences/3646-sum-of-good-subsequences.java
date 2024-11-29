class Solution {
    public int sumOfGoodSubsequences(int[] nums) {
        long dp[]=new long[100002];
        long sum[]=new long[100002];
        int mod = 1000000007;
        int n=nums.length;
        for(int i=0;i<n;i++){
            dp[nums[i]] = ((dp[nums[i]]%mod)+1+(dp[nums[i]+1]%mod))%mod;
            sum[nums[i]] = ((sum[nums[i]]%mod )+ (nums[i]%mod) + (sum[nums[i]+1]%mod) + ((dp[nums[i]+1]%mod) * (nums[i]%mod))%mod)%mod;
            if( nums[i]-1>=0){
                dp[nums[i]] = ((dp[nums[i]]%mod )+ (dp[nums[i]-1]%mod))%mod ;
                sum [nums[i]] = ((sum[nums[i]]%mod) + (sum[nums[i]-1]%mod) + ((dp[nums[i]-1]%mod)*(nums[i]%mod))%mod)%mod;
            }
            if(sum[nums[i]]<0)
                System.out.println(sum[nums[i]]);
        }
        long ans=0;
        for(long sums:sum){
            // if(ans<0)
            //     System.out.println(ans);
            ans=((ans%mod)+(sums%mod))%mod;
        }
        return (int)ans;
    }
}