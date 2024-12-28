int findMin(int* a, int n) {
    if(a[0]<a[n-1])
      return a[0];
    int left=0, right=n-1;
        while(left<right){
            int mid =(right+left)/2;
            if(a[mid]>a[mid+1]) return a[mid+1];
            else if(a[mid-1] >a[mid]) return a[mid];
            else if(a[0]<a[mid]) left=mid+1;
            else right=mid-1;
        }
    
    return a[0];
}