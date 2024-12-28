int findPeakElement(int* a, int n) {
    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1])
            return i;
    }
    return n-1;
}

// int findPeakElement(int* a, int n) {
//     int left=0, right = n-1,mid;
//     while(left<=right){
//         mid=(left+right)/2;
//         if(a[mid]>a[mid+1] && a[mid]>a[mid-1]) return mid;
//         else if(a[mid])
//     }
// }