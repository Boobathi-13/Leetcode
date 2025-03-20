int maxSideLength(int** mat, int m, int* matColSize, int t) {
        int n=*matColSize;

        int least=(m<n)?m:n;

        int **dp=(int**)calloc(m+1,sizeof(int*));

        for(int i=0;i<=m;i++)
            dp[i]=(int *)calloc(n+1,sizeof(int));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                dp[i+1][j+1]=mat[i][j]+dp[i+1][j]+dp[i][j+1]-dp[i][j];
            }
        }

        for(int k=least;k>0;k--){
            for(int i=k;i<=m;i++){
                for(int j=k;j<=n;j++)
                {
                    int sum=dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k];
                    if(sum<=t)
                        return k;
                }
            }
        }
        return 0;
}