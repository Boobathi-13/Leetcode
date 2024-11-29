class Solution {
    public int edgeScore(int[] edges) {
        long[] score = new long[edges.length];
        
        for(int i = 0; i < edges.length; i++){
            int to = edges[i];
            score[to] += i;
        }
        
        long ans = -1;
        int res = -1;

        for(int i = 0; i < score.length; i++){
            long x = score[i];
            if(x > ans){
                ans = x;
                res = i;
            }
        }
        return res;
    }
}