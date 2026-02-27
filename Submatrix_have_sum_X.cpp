#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<long long>> prefix(n + 1, vector<long long>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefix[i][j] = mat[i-1][j-1] 
                             + prefix[i-1][j] 
                             + prefix[i][j-1] 
                             - prefix[i-1][j-1];
            }
        }
        
        int count = 0;
        
        for (int len = 1; len <= min(n, m); len++) {
            for (int i = len; i <= n; i++) {
                for (int j = len; j <= m; j++) {
                    long long sum = prefix[i][j]
                                  - prefix[i-len][j]
                                  - prefix[i][j-len]
                                  + prefix[i-len][j-len];
                    
                    if (sum == x)
                        count++;
                }
            }
        }
        
        return count;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> mat(n, vector<int>(m));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    
    int x;
    cin >> x;
    
    Solution obj;
    cout << obj.countSquare(mat, x) << endl;
    
    return 0;
}
/*Number of submatrix have sum X
Difficulty: HardAccuracy: 77.78%Submissions: 6K+Points: 8
Given a matrix mat[][] of size n × m and an integer x, find the number of square submatrices whose sum of elements is equal to x.

Examples:

Input: mat[][] = [[2, 4, 7, 8, 10], 
               [3, 1, 1, 1, 1], 
               [9, 11, 1, 2, 1], 
               [12, -17, 1, 1, 1]] , 
x = 10
Output: 3
Explanation: The sub-squares whose sum of elements = 10, are colored in the matrix.

Input: mat[][] = [[3, 3, 5, 3], 
               [2, 2, 2, 6], 
               [11, 2, 2, 4]] ,
x = 1
Output: 0
Explanation: There is no sub-squares whose sum of elements is 1.
Constraints:
1 ≤ n, m ≤ 100
-103 ≤ mat[i] ≤ 103
-109 ≤ x ≤ 109
*/