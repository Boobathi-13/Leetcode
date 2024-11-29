class Solution {
    public String largestPalindromic(String num) {
        StringBuffer sb = new StringBuffer();
        Character maxDigit = null;

        Map<Character,Integer> counts = new HashMap<>();
        for(int i=0;i<num.length();i++){
            int count = counts.getOrDefault(num.charAt(i),0);
            count++;
            counts.put(num.charAt(i),count);
        }

        PriorityQueue<Map.Entry<Character,Integer>> pq = new PriorityQueue<>((a,b)->b.getKey()-a.getKey());
        
        for(Map.Entry<Character,Integer> entry: counts.entrySet()){
            //We add entries to the PQ only if their count is atleast 2 else we just update the maxDigit
            if(entry.getValue()>=2){
                pq.offer(entry);
            }else if(entry.getValue()==1 && (maxDigit==null || maxDigit<entry.getKey())){
                maxDigit = entry.getKey();
            }
        }

        boolean first = true;
        while(!pq.isEmpty()){
            Map.Entry<Character,Integer> entry = pq.poll();

            //Special Case: To Avoid Leading Zeros
            if(first){
                first = false;
                if(entry.getKey()=='0'){
                    //this means we have '0' in the given string, so atleast the maxDigit will be '0' instead of null
                    if(maxDigit==null){
                        maxDigit = '0';
                    }
                    continue;
                }
            }

            sb.append(entry.getKey()+"");
            int count = entry.getValue();
            count -= 2;
            //We add entries to the PQ only if their count is atleast 2 else we just update the maxDigit
            if(count>=2){
                entry.setValue(count);
                pq.offer(entry);
            }else if(count==1 && (maxDigit==null || maxDigit<entry.getKey())){
                maxDigit = entry.getKey();
            }
        }

        String str = sb.toString();
        String reverse = sb.reverse().toString();
        return str + (maxDigit==null?"":maxDigit) + reverse;
    }
}