class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pc = 0;
        unordered_map<int,int> m;
        for(auto i : nums){
            pc = pc + m[i];
            m[i] = m[i] + 1;
        }
        return pc;
    }
};