class Solution {
    ArrayList<Integer>[] graph;
    int[][] vis;
    int[] coins;
    public int maximumPoints(int[][] edges, int[] c, int k) {
        int n=c.length,st=0,val=0;
        vis = new int[14][n];
        coins=c;
        graph = new ArrayList[n];
        for(int i=0;i<n;i++)    graph[i]=new ArrayList<>();
        boolean[] visited = new boolean[n];
        for(int[] edge:edges){

            // parent will always be smaller value
            if(edge[1]<edge[0]){
                graph[edge[1]].add(edge[0]);
                continue;
            }
            graph[edge[0]].add(edge[1]);
        }
        for(int[] v:vis)    Arrays.fill(v,-1);
        val+= dfs(0,k,0);
        return val;
    }
    
    public int dfs(int st,int k,int shift){
        if(shift>=13)    return 0;
        if(vis[shift][st]>-1)    return vis[shift][st];
        int c=coins[st]>>(shift),way1=c-k,way2=(c>>1);
        for(int i:graph[st]){
            way1+=dfs(i,k,shift);
        }

        //if we can find answer by just subtracting then need not to go for second way
        if((c-k) >=(c>>1)){
            return vis[shift][st]=way1;
        }
        for(int i:graph[st]){
            way2+=dfs(i,k,shift+1);
        }
        return vis[shift][st]=Math.max(way1,way2);
    }
}