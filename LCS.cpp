// LONGEST COMMON SUBSEQUENCE-----------------------------------------------------------------------
ll dp[5001][5001];
ll solve(ll i, ll j, string &s1,string &s2){
    if(i < 0 or j < 0){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + solve(i-1,j-1,s1,s2);
    }
    else{
        return dp[i][j] = max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
    }
}
