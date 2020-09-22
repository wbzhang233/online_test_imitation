#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        int dp[m + 1][n + 1];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (text1[i] == text2[j])
                {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution2
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        // int dp[m+1][n+1];
        vector<vector<int> > dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    string text1 = "ilovezq";
    string text2 = "ilhlove";
    // string text1 = "abcde";
    // string text2 = "ace";
    Solution2 solu;
    int ans = solu.longestCommonSubsequence(text1, text2);
    cout << ans << endl;

    return 0;
}