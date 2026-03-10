#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> last(10, -1);

        // Store last occurrence of each digit
        for(int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }

        // Traverse the string
        for(int i = 0; i < n; i++) {
            for(int d = 9; d > s[i] - '0'; d--) {
                if(last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }

        return s;
    }
};

int main() {
    string s;
    cin >> s;

    Solution obj;
    cout << obj.largestSwap(s);

    return 0;
}
/*Largest number in one swap
Difficulty: EasyAccuracy: 48.67%Submissions: 40K+Points: 2
Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.

Examples:

Input: s = "768"
Output: "867"
Explanation: Swapping the 1st and 3rd characters(7 and 8 respectively), gives the lexicographically largest string.
Input: s = "333"
Output: "333"
Explanation: Performing any swaps gives the same result i.e "333".
Constraints:
1 ≤ |s| ≤ 105
'0' ≤ s[i] ≤ '9'
*/