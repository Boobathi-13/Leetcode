int kItemsWithMaximumSum(int o, int z, int n, int k) {
    int size = o+z+n;
    if(size==0) return 0;
    int a[size];
    int index = 0;
    int sum = 0;
    for(int i=0; i<o; i++) a[index++] = 1;
    for(int j=0; j<z; j++) a[index++] = 0;
    for(int k=0; k<n; k++) a[index++] = -1;
    for(int l=0; l<k; l++) sum += a[l];
    return sum;
}