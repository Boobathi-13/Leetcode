class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length+nums2.length;
        int temp[] = new int[n];
        int k = 0;
        for(int i=0; i<nums1.length; i++)
            temp[k++]=nums1[i];
        for(int j=0; j<nums2.length; j++)
            temp[k++]=nums2[j];
        Arrays.sort(temp);
        if(n%2!=0)
            return temp[n/2];
        else
            return (double)(temp[(n/2)-1] + temp[(n/2)])/2;
    }
}