double averageWaitingTime(int** a, long n, int* m) {
    double sum = 0, sum1 = 0;
    sum = a[0][0] + a[0][1];
    for(int i = 1; i<n; i++){
        for(int j=1; j<*m; j++){
            if(a[i][0]>=sum) sum = a[i][0] + a[i][j];
            else sum += a[i][j];
            printf("SUM : %d\n",sum);
        }
        sum1 += sum - a[i][0];
        printf("%d\n",sum1);
    }
    return (double)(a[0][1]+sum1)/n;
}