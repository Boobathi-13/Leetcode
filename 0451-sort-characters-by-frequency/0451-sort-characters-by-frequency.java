class Solution {
    public String frequencySort(String s) {
        HashMap<Character , Integer> map = new HashMap<>();
        for(char c:s.toCharArray()){
            map.put(c , map.getOrDefault(c , 0)+1);
        }
        List<Character> list = new ArrayList<>(map.keySet());
        Collections.sort(list , (a,b)->{
            int fa = map.get(a);
            int fb = map.get(b);
            if(fa!=fb){
                return fb-fa;
            }
            else return a-b;
        });
        StringBuilder sb = new StringBuilder();
        for(char c:list){
            sb.append(String.valueOf(c).repeat(map.get(c)));
        }
        return sb.toString();
    }
}