#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int n = arr1.size();
        int m = arr2.size();
        int i = 0, j = m - 1;
        int diff = INT_MAX;
        vector<int> ans(2);
        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            if (abs(sum - x) < diff) {
                diff = abs(sum - x);
                ans[0] = arr1[i];
                ans[1] = arr2[j];
            }
            if (sum > x)
                j--;
            else
                i++;
        }
        return ans;
    }
};
int main() {
    vector<int> arr1 = {1, 4, 5, 7};
    vector<int> arr2 = {10, 20, 30, 40};
    int x = 32;
    Solution obj;
    vector<int> res = obj.findClosestPair(arr1, arr2, x);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
/*Find the closest pair from two arrays
Difficulty: EasyAccuracy: 18.01%Submissions: 77K+Points: 2
Given two sorted arrays arr1[] and arr2[] of size n and m and a number x, find the pair whose sum is closest to x and the pair has an element from each array. In the case of multiple closest pairs return any one of them.

Note : In the driver code, the absolute difference between the sum of the closest pair and x is printed.

Examples:

Input : arr1[] = [1, 4, 5, 7], arr2[] = [10, 20, 30, 40], x = 32
Output : [1, 30]
Explanation:The closest pair whose sum is closest to 32 is [1, 30] = 31.
Input : arr1[] = [1, 4, 5, 7], arr2[] = [10, 20, 30, 40], x = 50 
Output : [7, 40] 
Explanation: The closest pair whose sum is closest to 50 is [7, 40] = 47.
Constraints:
1 ≤ arr1.size(), arr2.size() ≤ 105
1 ≤ arr1[i], arr2[i] ≤ 109
1 ≤ x ≤ 109
*/