class Solution {
    public int longestAwesome(String s) {
        HashMap<Integer,Integer> prevSeenIndex = new HashMap();
        int ans = 0;
        int mask = 0;
        prevSeenIndex.put(0,-1);
        int k =0;
        for(char c: s.toCharArray())
        {
            int no = c-'0';
            int binaryRepresentation = 1<<(no+1);
            mask = mask^binaryRepresentation;
            int length = k-prevSeenIndex.getOrDefault(mask,k)+1;
            ans = Math.max(length,ans);
            for(int i=0;i<=9;i++)
            {
                 binaryRepresentation = 1<<(i+1);
                length= k - prevSeenIndex.getOrDefault(mask^binaryRepresentation,k)+1;
                ans = Math.max(length,ans);
            }
            if(!prevSeenIndex.containsKey(mask))
                prevSeenIndex.put(mask,k);
            k++;
        }
        return ans-1;
    }

}