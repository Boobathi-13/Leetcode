class Solution {
public:
    vector<string>ans;
    vector<string> restoreIpAddresses(string s) 
    {  
         int idx=0;
         string str="";
         int count=0;
         fun(s,idx,str,count);
         return ans;
    }
    void fun(string &s , int idx ,string str,int count)
    {
         if(idx >= s.length())
         {
            if(count==4)
            {
              str.pop_back();
              ans.push_back(str);
              return;	
          }
            else
            {
                return;
            }

         }

         int num=0;
         string temp="";

         for(int i=idx;i<s.length();i++)
         {
             char ch = s[i];
             int digit = ch - '0';

             num = (num*10) + digit;
             temp.push_back(ch);

             //we need to check for the leading zeor's
              if(temp.length()>1 and temp[0]=='0' and (num>0 or num==0)) 
              {
                 return;	
              }

             //now if eveything is ok then call for next segment
             if((num>=0 and num<=255))
             {
               fun(s,i+1,str+temp+'.',count+1);	
             }
             else
             {
               return;	
             }

         }
    }
};