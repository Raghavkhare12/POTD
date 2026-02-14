#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinDiff(vector<int>& arr, int m) {
        int n = arr.size();
        
        // Edge case: if students are more than packets
        if (m > n) return 0;
        
        // Sort the packets
        sort(arr.begin(), arr.end());
        
        int minDiff = INT_MAX;
        
        // Traverse using sliding window of size m
        for (int i = 0; i + m - 1 < n; i++) {
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        
        return minDiff;
    }
};

int main() {
    vector<int> arr = {3, 4, 1, 9, 56, 7, 9, 12};
    int m = 5;

    Solution obj;
    cout << obj.findMinDiff(arr, m) << endl;

    return 0;
}

/*Chocolate Distribution Problem
Difficulty: EasyAccuracy: 49.91%Submissions: 268K+Points: 2Average Time: 15m
Given an array arr[] of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets among m students such that -
      i. Each student gets exactly one packet.
     ii. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum and return that minimum possible difference.

Examples:

Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing following m packets :[3, 4, 9, 7, 9].
Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing following m packets :[3, 2, 4].
Input: arr = [3, 4, 1, 9, 56], m = 5
Output: 55
Explanation: With 5 packets for 5 students, each student will receive one packet, so the difference is 56 - 1 = 55.
Constraints:
1 ≤ m <= arr.size ≤ 105
1 ≤ arr[i] ≤ 109*/