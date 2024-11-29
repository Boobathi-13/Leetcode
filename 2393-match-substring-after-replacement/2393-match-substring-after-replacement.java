class Solution {
    public boolean matchReplacement(String s, String sub, char[][] mappings) 
    {
        int n=mappings.length;
        Map<Character,Set<Character>> map=new HashMap<>();
        
        for(int i=0;i<n;i++)
        {
            if(!map.containsKey(mappings[i][0]))
            map.put(mappings[i][0],new HashSet<>());
            
            map.get(mappings[i][0]).add(mappings[i][1]);
        }
        
        for(int i=0;i<s.length()-sub.length()+1;i++)
        {
            int f=-1; int pos=i;
            
            for(int j=0;j<sub.length();j++)
            {
                
                if(s.charAt(pos)==sub.charAt(j))
                pos++;
                
                
                else if(!map.containsKey(sub.charAt(j)) || !map.get(sub.charAt(j)).contains(s.charAt(pos)))
                {
                    f++; break;
                }
                
                else
                pos++;
                    
            }
            
            if(f==-1)
            return true;
        }
        
        return false;
    }
}