class Solution {
    public int minAbsDifference(int[] nums, int goal) {
    List<Integer> set1=new ArrayList<>();
    List<Integer> set2=new ArrayList<>();
    
    GetAllsubSequenceSum(0,(nums.length-1)/2,nums, set1, 0);
    GetAllsubSequenceSum(((nums.length-1)/2)+1,nums.length-1,nums, set2, 0);
    int min=Integer.MAX_VALUE;
        Collections.sort(set2);
        
        int sum=0;
        for(int first:set1){
            int remainingPart=goal-first;            
            int pos = Collections.binarySearch(set2, remainingPart);
           if(pos>=0)
               return 0;
           else{
               int position= -1*(pos+1);
               int low=position-1;
                if(low>=0)
                  min=Math.min(min, Math.abs(first+set2.get(low)-goal));
                if(low!=set2.size()-1)
                  min=Math.min(min, Math.abs(first+set2.get(position) - goal));
           } 
        }  
    return min;
    
    }    
    
        public void GetAllsubSequenceSum(int initial, int length, int[] nums, List<Integer> data, int sum){
            if(initial==length+1){
                data.add(sum);
                return;
            }
            GetAllsubSequenceSum(initial+1,length,nums,data,sum+nums[initial]);
            GetAllsubSequenceSum(initial+1,length,nums,data,sum);
        }      
}