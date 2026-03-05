#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);

        int left = 0, right = 0;
        int distinct = 0;
        int ans = -1;

        while (right < n) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;

            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }

            if (distinct == k)
                ans = max(ans, right - left + 1);

            right++;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string s = "aabacbebebe";
    int k = 3;

    cout << obj.longestKSubstr(s, k);

    return 0;
}
/*Longest Substring with K Uniques
Difficulty: MediumAccuracy: 34.65%Submissions: 276K+Points: 4
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
*/