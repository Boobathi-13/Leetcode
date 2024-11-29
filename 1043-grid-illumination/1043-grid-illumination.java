class Solution {
    public int[] gridIllumination(int n, int[][] lamps, int[][] queries) {
        
        Map<Integer, Integer> m1 = new HashMap<>();
        Map<Integer, Integer> m2 = new HashMap<>();
        Map<Integer, Integer> m3 = new HashMap<>();
        Map<Integer, Integer> m4 = new HashMap<>();
        Map<Integer, Integer> m5 = new HashMap<>();

        for(int i=0;i<lamps.length;i++){
            int x=lamps[i][0];
            int y=lamps[i][1];

            m1.put(x, m1.getOrDefault(x,0)+1);
            m2.put(y, m2.getOrDefault(y,0)+1);
            m3.put(x-y, m3.getOrDefault(x-y,0)+1);
            m4.put(x+y, m4.getOrDefault(x+y,0)+1);
            m5.put(x*n+y, m5.getOrDefault(x*n+y,0)+1);
        }
            int[] ans = new int[queries.length];
            int[][] dirs = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{0,0}};

            for(int i=0;i<queries.length;i++){
                int x=queries[i][0];
                int y=queries[i][1];

                if(m1.getOrDefault(x,0)>0 || m2.getOrDefault(y,0)>0
                || m3.getOrDefault(x-y,0)>0 || m4.getOrDefault(x+y,0)>0){
                    ans[i]=1;
                } else {
                    ans[i]=0;
                }

                for(int[] dir : dirs){
                    int x1 = x + dir[0];
                    int y1 = y + dir[1];

                    if(x1>=0 && y1>=0 && x1<n && y1<n && m5.containsKey(x1*n+y1)){
                        int time = m5.get(x1*n+y1);

                        m1.put(x1, m1.getOrDefault(x1,0)-time);
                        m2.put(y1, m2.getOrDefault(y1,0)-time);
                        m3.put(x1-y1, m3.getOrDefault(x1-y1,0)-time);
                        m4.put(x1+y1, m4.getOrDefault(x1+y1,0)-time);
                        m5.remove(x1*n+y1);
                    }
                }

            }
            return ans;

    }
}