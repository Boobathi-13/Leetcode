class Solution {
    public boolean isSubstringPresent(String s) {
        // add all substring of size 2 into set
        Set<String> set = new HashSet();
        for(int i =0; i+2<=s.length(); i++)
            set.add(s.substring(i, i+2));

        // check if any substrin of size 2 from the reversed string is present in set
        StringBuilder sb = new StringBuilder(s).reverse();
        for(int i =0; i+2<=sb.length(); i++)
            if(set.contains(sb.substring(i, i+2)))
                return true;
        return false;
    }
}