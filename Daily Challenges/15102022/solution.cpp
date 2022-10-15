int dp[101][27][101][101];
class Solution {
public:
    int n;
    string str;
    int getLengthOfOptimalCompression(string s, int k) {
        n=s.size();
        str=s;
        memset(dp,-1,sizeof(dp));
        return solution(0,26,0,k);//Index,Prev Char,Length of frequency,number of deletions
    }
    
    int solution(int index, int prev, int len, int k)
    {
        if(k<0)
            return 1e9;
        if(index>=n)
            return 0;
        // if(index<101&&prev<27&&len<101&&k<101)
        if(dp[index][prev][len][k]+1)
            return dp[index][prev][len][k];
        int del=solution(index+1,prev,len,k-1);
        int ndel=0;
        if(str[index]-'a'==prev)
        {
            if(len==1||len==9||len==99)
                ndel=1+solution(index+1,str[index]-'a',len+1,k);
            else
                ndel=solution(index+1,str[index]-'a',len+1,k);
        }
        else
            ndel=1+solution(index+1,str[index]-'a',1,k);
        return dp[index][prev][len][k]= min(ndel,del);
    }
};