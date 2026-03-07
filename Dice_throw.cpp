#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int noOfWays(int m, int n, int x) {
        
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= x; j++) {
                for(int k = 1; k <= m; k++) {
                    if(j - k >= 0) {
                        dp[i][j] += dp[i - 1][j - k];
                    }
                }
            }
        }

        return dp[n][x];
    }
};

int main() {
    
    int m = 6, n = 3, x = 12;

    Solution obj;
    cout << obj.noOfWays(m, n, x);

    return 0;
}
/*Dice throw
Difficulty: MediumAccuracy: 36.52%Submissions: 57K+Points: 4Average Time: 30m
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.
Constraints:
1 <= m,n,x <= 50
*/