class Solution {
    public String shortestSuperstring(String[] words) {
        Map<String,String> map=new HashMap<>();
        //mark every word as unused
        int unusedWords=0; //integer is used as a bit array
        for(int i=0;i<words.length;i++) {
            unusedWords|=1<<i; //marking every word as unused
        }
        //calling the recursive function to find the shortest superstring
        return shortestSuperstring(words,"",unusedWords,map);
    }
    //recursive function to find the shortest superstring
    public String shortestSuperstring(String words[], String startWord, int unused, Map<String,String> map){
        if(unused==0) { //base case: all words have been used
            return startWord;
        }

        //create a unique key for the current start word and unused words combination
        String key=startWord+"|"+unused;
        //if the result for this combination has already been calculated, return it
        if(map.containsKey(key)){
            return map.get(key);
        }

        String shortest=null;
        for(int i=0;i<words.length;i++) {
            if(!isConsumed(unused,i)) { //if the i-th word has not been used yet
                //get the shortest superstring starting from the i-th word
                String superstring=shortestSuperstring(words,words[i],consume(unused,i),map);

                //"append" the shortest superstring to the start word
                String appended=overlapAppend(startWord,superstring);

                //keep the shortest
                if(shortest==null || appended.length()<shortest.length()) {
                    shortest=appended;
                }
            }
        }
        //cache the result for this combination
        map.put(key,shortest);
        return shortest;
    }

    //Concatenate string a to b. For example, "bake" and "kelt" => "bakelt"
    public String overlapAppend(String a, String b) {
        for(int i=Math.max(1,a.length()-b.length());i<a.length();i++) {
            boolean match=true;
            for(int j=i;j<a.length();j++) {
                if(a.charAt(j)!=b.charAt(j-i)) {
                    match=false;
                    break;
                }
            }
            if(match) {
                return a.substring(0,i)+b;
            }
        }
        return a+b;
    }

    //check if the i-th word has been used or not
    public boolean isConsumed(int unused, int i) {
        return ((unused>>i)&1)==0;
    }

    //consume the i-th word (mark it as used) 
    public int consume(int unused, int i) {
        return unused & ~(1<<i);
    }
}