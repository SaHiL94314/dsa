class Solution {
private:
    int findsum(int ind,int tight,int cursum,string &s,vector<vector<vector<int>>>&dp){
        if(ind==s.size()) return cursum;
        
        if(dp[ind][tight][cursum]!=-1) return dp[ind][tight][cursum];
        
        int limit=tight?s[ind]-'0':9;
        int res=0;
        for(int d=0;d<=limit;d++){
            int newtight = tight & (d==limit);
            if(d==1) res+=findsum(ind+1,newtight,cursum+1,s,dp);
            else res+=findsum(ind+1,newtight,cursum,s,dp);
        }
        return dp[ind][tight][cursum]=res;
    }
public:
    int countDigitOne(int n) {
        string s=to_string(n);
        int sz=s.size();
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(2,vector<int>(sz*1+1,-1)));
        // memset(dp,-1,sizeof(dp));
        
        return findsum(0,1,0,s,dp);
    }
};
