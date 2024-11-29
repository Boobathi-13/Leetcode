class Solution {
  public List<String> findRepeatedDnaSequences(String s) {
      int L = 10;
      HashSet<String> seen = new HashSet<String>();
      HashSet<String> output = new HashSet<String>();
      for(int i = 0;i<=s.length() - L;i++){
          String value = s.substring(i,i+L);
          if(!seen.add(value)) output.add(value);
      }
      return new ArrayList<String>(output);
  }
}