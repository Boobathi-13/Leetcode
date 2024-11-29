class Solution {
    public int maximumLengthSubstring(String s) {
        int a[]=new int[26];
        int maxi=0,i=0,i1=0;
        for(i=0,i1=0;i<s.length();i++)
        {
            char c=s.charAt(i);
            a[c-'a']++;
            int count=0;
            for(int j=0;j<26;j++)
            {
                if(a[j]>2)
                {
                    count++;
                }
            }
            if(count==1)
            {
                maxi=Math.max(maxi,i-i1);
                //System.out.println(maxi);
                while(count!=0)
                {
                    count=0;
                    a[s.charAt(i1)-'a']--;
                    i1++;
                    for(int j=0;j<26;j++)
                    {
                        if(a[j]>2)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return Math.max(maxi,(i-i1));
    }
}