#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

    bool valid(string s) {
        if(s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void solve(string &s, int idx, int parts, string curr, vector<string> &ans) {

        if(parts == 4 && idx == s.size()) {
            curr.pop_back(); 
            ans.push_back(curr);
            return;
        }

        if(parts >= 4) return;

        for(int len = 1; len <= 3; len++) {

            if(idx + len > s.size()) break;

            string part = s.substr(idx, len);

            if(valid(part)) {
                solve(s, idx + len, parts + 1, curr + part + ".", ans);
            }
        }
    }

    vector<string> generateIp(string &s) {

        vector<string> ans;

        if(s.size() < 4 || s.size() > 12) return ans;

        solve(s, 0, 0, "", ans);

        return ans;
    }
};

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;
    vector<string> result = obj.generateIp(s);

    if(result.empty()) {
        cout << -1;
    }
    else {
        for(string ip : result)
            cout << ip << endl;
    }

    return 0;
}
/*Generate IP Addresses
Difficulty: MediumAccuracy: 38.71%Submissions: 55K+Points: 4Average Time: 30m
Given a string s containing only digits, your task is to restore it by returning all possible valid IP address combinations. You can return your answer in any order.

A valid IP address must be in the form of A.B.C.D, where A, B, C, and D are numbers from 0-255(inclusive).

Note: The numbers cannot be 0 prefixed unless they are 0. For example, 1.1.2.11 and 0.11.21.1 are valid IP addresses while 01.1.2.11 and 00.11.21.1 are not.
If there are no possible valid IP address return an empty list. The driver code will print -1 in this case.

Examples:

Input: s = “255678166”
Output: [“25.56.78.166”, “255.6.78.166”, “255.67.8.166”, “255.67.81.66”]
Explanation: These are the only valid possible IP addresses.
Input: s = “25505011535”
Output: []
Explanation: We cannot generate a valid IP address with this string.
Constraints:
1 ≤ s.size() ≤ 16
s contains only digits(i.e. 0-9)
*/