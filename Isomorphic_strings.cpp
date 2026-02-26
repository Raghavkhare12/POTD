#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.length() != s2.length()) return false;
        
        vector<int> map1(256, -1);
        vector<int> map2(256, -1);
        
        for(int i = 0; i < s1.length(); i++) {
            char c1 = s1[i];
            char c2 = s2[i];
            
            if(map1[c1] == -1 && map2[c2] == -1) {
                map1[c1] = c2;
                map2[c2] = c1;
            }
            else {
                if(map1[c1] != c2 || map2[c2] != c1)
                    return false;
            }
        }
        
        return true;
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    Solution obj;
    cout << (obj.areIsomorphic(s1, s2) ? "true" : "false");
    
    return 0;
}
/*Isomorphic Strings
Difficulty: EasyAccuracy: 34.21%Submissions: 226K+Points: 2Average Time: 30m
Given two strings s1 and s2 consisting of only lowercase English letters and of equal length, check if these two strings are isomorphic to each other.
If the characters in s1 can be changed to get s2, then two strings, s1 and s2 are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.

Examples:

Input: s1 = "aab", s2 = "xxy"
Output: true
Explanation: Each character in s1 can be consistently mapped to a unique character in s2 (a → x, b → y).
Input: s1 = "aab", s2 = "xyz"
Output: false
Explanation: Same character 'a' in s1 maps to two different characters 'x' and 'y' in s2.
Input: s1 = "abc", s2 = "xxz"
Output: false
Explanation: Two different characters 'a' and 'b' in s1 maps with same character 'x' in s2. 
Constraints:
1 ≤ s1.size() = s2.size() ≤ 105
*/