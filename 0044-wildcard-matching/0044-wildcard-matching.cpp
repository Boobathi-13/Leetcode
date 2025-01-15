class Solution {
public:
    string s1,s2;
    int m,n;
    int dp[2001][2001];
    int fn(int i,int j){
        if(i>=m && j>=n) return 1;
        if(i>=m){
            for(int k=j;k<n;k++) if(s2[k]!='*') return 0;
            return 1;
        }
        if(j>=n){
            for(int k=i;k<m;k++) if(s1[k]!='*') return 0;
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s2[j]>='a' && s2[j]<='z'){
                 if(s2[j]==s1[i]) return dp[i][j]=fn(i+1,j+1);
                 return dp[i][j]=0;
             } 
       else if(s2[j]=='?') return dp[i][j]=fn(i+1,j+1);
       return dp[i][j]=fn(i,j+1)||fn(i+1,j+1)||fn(i+1,j);
    }
    bool isMatch(string s, string p) {
        s1=s,s2=p;
        m=s1.size(),n=s2.size();
        memset(dp,-1,sizeof(dp));
        return fn(0,0);
    }
};