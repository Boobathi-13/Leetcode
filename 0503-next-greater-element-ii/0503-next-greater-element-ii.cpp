class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Initialize the answer vector with -1
        stack<int> s;
        
        // Traverse the array twice to simulate circular array
        for (int i = 0; i < 2 * n; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            // Push the current index onto the stack
            s.push(i % n);
        }
        
        return ans;
    }
};