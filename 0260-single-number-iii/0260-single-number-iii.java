class Solution {
    public int[] singleNumber(int[] nums) {
        long xor=0;
        for(int num:nums){
            xor=xor^num;
        }
        int first_diff_digit=(int)((xor&(xor-1))^xor);
        int n1=0;
        int n2=0;
        for(int num:nums){
            if((num&first_diff_digit)==0){
                n1=n1^num;
            }
            else{
                n2=n2^num;
            }
        }
        return new int[]{n1,n2};
    }
}