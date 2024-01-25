// 01-> iterative: [ok]
int longestCommonSubsequence(string s, string t) {
      int n=s.size();
      int m=t.size();

      int dp[n+1][m+1];
      for(int i=0; i<=n; i++){
         for(int j=0; j<=m; j++) dp[i][j]=0;
      }

      for(int i=1; i<=n; i++){
          for(int j=1; j<=m; j++){
              if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
              else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }

      return dp[n][m];
}

// 02
int lcsIterative(string S, string W) {
    int n = S.size();
    int m = W.size();
    
    for (int i = 0;i < n;i++) mem[i][m] = 0;
    for (int j = 0;j < m;j++) mem[n][j] = 0;
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (S[i] == W[j]) {
                mem[i][j] = mem[i + 1][j + 1] + 1;
            } else {
                mem[i][j] = max(mem[i + 1][j], mem[i][j + 1]);
            }
        }
    }
    
    return mem[0][0];
}
