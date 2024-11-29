class Solution {

    static boolean isequal(int counta[],int countb[]){
       
        boolean ans=true;
        for(int i=0;i<26;i++){
            if(counta[i]!=countb[i]){
                ans= false;
                break;
            }
        }
        return ans;

    }

    public List<Integer> findAnagrams(String s, String p) {
        int k=p.length();
        List<Integer> l=new ArrayList<>();
        if(s.length()<k){
            return l;
        }
        
        int counts[]=new int[26];
        int countp[]=new int[26];
        for(int i=0;i<k;i++){
            counts[s.charAt(i)-'a']++;
            countp[p.charAt(i)-'a']++;
        }
        if(isequal(counts,countp)){
            l.add(0);
        }
        for(int i=k;i<s.length();i++){
            counts[s.charAt(i)-'a']++;
            counts[s.charAt(i-k)-'a']--;
            if(isequal(counts,countp)){
                l.add(i-k+1);
            }
        }
        return l;
    }
}