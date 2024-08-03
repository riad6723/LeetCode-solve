class Solution {
public:

    bool dp[2010][2010];
    int memo[2010];

    void koro(string str) {
        memset(dp,false,sizeof(dp));
        memset(memo,-1,sizeof(memo));

        for(int i=0;i<str.size();i++) dp[i][i] = true;
        for(int i=0;i+1<str.size();i++) {
            if(str[i] == str[i+1]) dp[i][i+1] = true;
        }

        for(int i=3;i<=str.size();i++) {
            for(int j=0;j+i-1<str.size();j++) {
                int l = j;
                int r = l + i - 1;
                if(dp[l+1][r-1] == true and str[l] == str[r])
                dp[l][r] = true;
            }
        }
    }

    int rec(string &str, int pos) {
        //base case
        if(pos == str.size()) return 0;
        if(memo[pos] != -1) return memo[pos];

        int ans = 1e9;
        for(int i=pos;i<str.size();i++) {
            if(dp[pos][i] == true) {
                ans = min(ans, rec(str, i+1) + 1);
            }
        }
        return memo[pos] = ans;
    }

    int minCut(string s) {
        koro(s);
        return rec(s, 0) - 1;
    }
};
