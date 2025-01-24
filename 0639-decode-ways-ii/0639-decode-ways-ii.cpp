class Solution {
public:
    long long M = 1000000007;
    long long solve(int i,string &s,vector<int> &dp){
        if(i<0) return 1;
        if(dp[i]!=-1) return dp[i];
        
        long long count = 0;
        
        if(s[i]=='*'){
            count = (count + 9*solve(i-1,s,dp))%M;
            if((i>0) && (s[i-1]=='1'))
                count = (count + 9*solve(i-2,s,dp))%M;
            if((i>0) && (s[i-1]=='2'))
                count = (count + 6*solve(i-2,s,dp))%M;
            if((i>0) && (s[i-1]=='*'))
                count = (count + 15*solve(i-2,s,dp))%M;  
        }
        else{
            if(s[i]!='0')
                count = (count + solve(i-1,s,dp))%M;
            if((i>0) && (s[i-1]=='1'))
                count = (count + solve(i-2,s,dp))%M;
            if(i>0 && s[i-1]=='2' && s[i]<='6')
                count = (count + solve(i-2,s,dp))%M;
            if(i>0 && s[i-1]=='*'){
                if(s[i]<='6') count =  (count + 2*solve(i-2,s,dp))%M;
                else count =  (count + 1*solve(i-2,s,dp))%M;
            }
        }        
        
        return dp[i] = count;
    }
    
    
    
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(n-1,s,dp);
    }
};