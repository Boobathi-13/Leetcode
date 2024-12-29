int minDays(int* bloomDay, long n, long m, long k) {
    if(n<m*k) return -1;
    int maxDay = 0;
    for(int i=0; i<n; i++){
        maxDay = fmax(maxDay,bloomDay[i]);
    }
    // for(int day = 1; day<=maxDay; day++){
    //     int bc=0, nofb=0;
    //     for(int i=0; i<n; i++){
    //         if(bloomDay[i]<=day) bc++;
    //         else bc=0;
    //         if(bc>=k){
    //             nofb++;
    //             bc=0;
    //         }
    //     }
    //     if(nofb>=m) return day;
    // }
    int left = 1, right = maxDay, mid;
    while(left<right){
        mid=(left+right)/2;
        int bc=0, nofb=0;
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=mid) bc++;
            else bc=0;
            if(bc>=k){
                nofb++;
                bc=0;
            }
        }
        if(nofb>=m) right=mid;
        else left=mid+1;
    }
    return left;
}