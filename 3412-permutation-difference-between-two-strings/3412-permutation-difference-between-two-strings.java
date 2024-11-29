class Solution {
    public int findPermutationDifference(String s, String t) {
        Map<Character,Integer> map=new HashMap<>();
        int absDiff=0;
        for(int i=0;  i<s.length();  i++){
            char ch=s.charAt(i);
            map.put(ch,i);//map of character with it's indices

        }

        //now we will itearte on 2nd string to look for absolute diff between indices sum
        for(int i=0;  i<t.length();  i++){
            char ch=t.charAt(i);
            int j=map.get(ch);

            absDiff+=Math.abs(i-j);

        }

        return absDiff;

        
    }
}