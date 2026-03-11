#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Previous smaller element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            if(st.empty()) left[i] = i + 1;
            else left[i] = i - st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next smaller element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if(st.empty()) right[i] = n - i;
            else right[i] = st.top() - i;

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++)
            ans += (long long)arr[i] * left[i] * right[i];

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    cout << obj.sumSubMins(arr);

    return 0;
}
/*Sum of subarray minimums
Difficulty: MediumAccuracy: 46.92%Submissions: 38K+Points: 4Average Time: 30m
Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.

Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

Examples:

Input: arr[] = [10, 20]
Output: 40
Explanation: Subarrays are [10], [20], [10, 20]. Minimums are 10, 20, 10.
Sum of all these is 40.
Input: arr[] = [1, 2, 3, 4]
Output: 20
Explanation: Subarrays are [1], [2], [3], [4], [1, 2], [1, 2, 3], [1, 2, 3, 4], [2, 3], [2, 3, 4], [3, 4]. Minimums are 1, 2, 3, 4, 1, 1, 1, 2, 2, 3.
Sum of all these is 20.
Constraints:
1 ≤ arr.size() ≤ 3*104
1 ≤ arr[i] ≤ 103
*/