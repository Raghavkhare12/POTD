#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        unordered_map<int, int> firstIndex;
        int prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < a1.size(); i++) {
            prefix += (a1[i] - a2[i]);

            // If prefix becomes zero, span from 0 to i
            if (prefix == 0) {
                maxLen = max(maxLen, i + 1);
            }

            // If prefix seen before, update max length
            if (firstIndex.find(prefix) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefix]);
            } 
            else {
                firstIndex[prefix] = i;
            }
        }
        return maxLen;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++) cin >> a1[i];
    for (int i = 0; i < n; i++) cin >> a2[i];
    Solution obj;
    cout << obj.equalSumSpan(a1, a2);
    return 0;
}
/*Longest Span in two Binary Arrays
Difficulty: MediumAccuracy: 48.22%Submissions: 34K+Points: 4
Given two binary arrays, a1[] and a2[] of equal length. Find the length of longest common span (i, j), where i<= j such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

Examples:

Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 (0-based indexing).
Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 (0-based indexing).
Input: a1[] = [0, 0, 0], a2[] = [1, 1, 1]
Output: 0
Explanation: There is no span where the sum of the elements in a1[] and a2[] is equal.
Constraints:
1 ≤ a1.size() = a2.size() ≤ 106
0 ≤ a1[i], a2[i] ≤ 1
*/