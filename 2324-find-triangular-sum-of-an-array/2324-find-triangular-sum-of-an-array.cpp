class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size()>1){
            vector<int>k;
            for (int i=0;i<nums.size()-1;i++){
                k.push_back((nums[i]+nums[i+1])%10);
            }
            nums=k;
        }
        return nums[0];
    }
};