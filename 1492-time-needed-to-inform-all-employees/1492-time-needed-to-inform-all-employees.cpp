class Solution {  
public:  
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {  
        if(n == 1) return 0;  
        
        vector<vector<int>> arr(n);  
        for(int i = 0; i < n; i++) {  
            if(manager[i] != -1) arr[manager[i]].push_back(i);  
        }  

        queue<pair<int,int>> q;  
        int ans = 0;  
        q.push({headID, 0});  

        while(!q.empty()) {  
            int node = q.front().first;  
            int time = q.front().second;  
            q.pop();  

            ans = max(ans, time);  

            for(auto it : arr[node]) {  
                q.push({it, time + informTime[node]});  
            }  
        }  

        return ans;  
    }  
};