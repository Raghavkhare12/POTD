#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int prefixSum = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1;

            if(prefixSum > 0)
                ans = i + 1;

            if(mp.find(prefixSum) == mp.end())
                mp[prefixSum] = i;

            if(mp.find(prefixSum - 1) != mp.end())
                ans = max(ans, i - mp[prefixSum - 1]);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    Solution obj;
    cout << obj.longestSubarray(arr, k);
    return 0;
}
/*Longest Subarray with Majority Greater than K
Difficulty: MediumAccuracy: 52.63%Submissions: 30K+Points: 4
Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
0 ≤ k ≤ 106
*/