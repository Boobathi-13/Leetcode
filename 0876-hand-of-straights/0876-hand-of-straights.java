class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        int n=hand.length;
        if(n%groupSize!=0) return false;
        int groups=n/groupSize;
        Arrays.sort(hand);
        int start=0;
        for(int i=0;i<groups;i++){
            int cnt[]=new int[groupSize];
            cnt[0]=hand[start];
            hand[start]=-1;
            int idx=0;
            boolean flag=false;
            for(int j=start+1;j<n;j++){
                if(idx==groupSize-1){
                    if(flag==false){
                        start=j;
                    }
                    break;
                }
                if(hand[j]!=-1&&hand[j]-cnt[idx]>1){
                    return false;
                }
                else if(hand[j]!=-1&&hand[j]-cnt[idx]==1){
                    cnt[++idx]=hand[j];
                    hand[j]=-1;
                }
                else if(hand[j]!=-1&&hand[j]==cnt[idx]&&flag==false){
                    if(i==groups-1){
                        return false;
                    }
                   flag=true;
                   start=j;
                }
               
            }
        }
        return true;

    }
}