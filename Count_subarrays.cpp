#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nextSmaller(n);

        // Find next smaller element for each index
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty())
                nextSmaller[i] = n;
            else
                nextSmaller[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            ans += (nextSmaller[i] - i);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.countSubarrays(arr);

    return 0;
}
/*Subarrays with First Element Minimum
Difficulty: MediumAccuracy: 56.75%Submissions: 12K+Points: 4
You are given an integer array arr[ ]. Your task is to count the number of subarrays where the first element is the minimum element of that subarray.

Note: A subarray is valid if its first element is not greater than any other element in that subarray.

Examples:

Input: arr[] = [1, 2, 1]
Output: 5
Explanation:
All possible subarrays are:
[1], [1, 2], [1, 2, 1], [2], [2, 1], [1]
Valid subarrays are:
[1], [1, 2], [1, 2, 1], [2], [1] -> total 5
Input: arr[] = [1, 3, 5, 2]
Output: 8
Explanation:
Valid subarrays are: [1], [1, 3], [1, 3, 5], [1, 3, 5, 2], [3], [3, 5], [5], [2] -> total 8
Constraints:
1 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 105
*/