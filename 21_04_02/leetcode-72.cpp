class Solution {
private:
    
public:
    int minDistance(string word1, string word2) {
        const int N = 512;
        int dp[N][N];
        memset(dp, 0x3f, N * N * sizeof(int));
        dp[0][0] = 0;
        const char* char1 = &word1[0];
        const char* char2 = &word2[0];
        const int length1 = word1.length();
        const int length2 = word2.length();

        for(int i=0; i<=length1; i++) {
            for (int j=0; j<=length2; j++) {
                dp[i+1][j] = std::min(dp[i][j] + 1, dp[i+1][j]);
                dp[i][j+1] = std::min(dp[i][j] + 1, dp[i][j+1]);
                if (i < length1 && j < length2) {
                    if (char1[i] == char2[j]) dp[i+1][j+1] = std::min(dp[i][j], dp[i+1][j+1]);
                    else dp[i+1][j+1] = std::min(dp[i][j] + 1, dp[i+1][j+1]);
                }
            }
        }
        for(int i=0; i<=length1; i++) {
            for (int j=0; j<=length2; j++) {
                std::cout << dp[i][j] << ' ';
            }
            std::cout << std::endl;
        }
        return dp[length1][length2];

    }
};
