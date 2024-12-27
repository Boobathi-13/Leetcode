int trap(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int ml = height[l];
    int mr = height[r];
    int water = 0;
    while(l < r) {
        if(ml < mr) {
            l++;
            ml = (ml > height[l]) ? ml : height[l];
            water += ml - height[l];
        }
        else {
            r--;
            mr = (mr>height[r]) ? mr : height[r];
            water += mr - height[r];
        }
    }
    return water;
}