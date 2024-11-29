class Encrypter {
      HashMap<Character,String>mp;
      HashMap<String,Integer>mp1;
    public Encrypter(char[] keys, String[] values, String[] dictionary) {
        mp=new HashMap<>();
        mp1=new HashMap<>();

        for(int i=0;i<keys.length;i++){
           mp.put(keys[i],values[i]);
        }
        for (int i = 0; i < dictionary.length; i++) {
            String result = encrypt(dictionary[i]);
            mp1.put(result, mp1.getOrDefault(result,0 ) + 1);
        }
    }
    
    public String encrypt(String world1) {
         StringBuilder sb=new StringBuilder("");
         for(int i=0;i< world1.length();i++){
              sb.append(mp.getOrDefault(world1.charAt(i)," "));
         }
       return sb.toString();  
}
    
    public int decrypt(String word2) {
        return mp1.getOrDefault(word2, 0);
    }
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter obj = new Encrypter(keys, values, dictionary);
 * String param_1 = obj.encrypt(word1);
 * int param_2 = obj.decrypt(word2);
 */