class Solution {
    public void dfs(int[][] isConnected,int u,boolean[] flag){
        if(flag[u] == true){
            return;
        }

        flag[u] = true;

        for(int i = 0; i < isConnected.length; i++){
            if(isConnected[u][i] == 1){
                dfs(isConnected,i,flag);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        boolean[] flag = new boolean[n];
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(flag[i] == false){
                dfs(isConnected,i,flag);
                ans += 1;
            }
        }

        return ans;
    }
}