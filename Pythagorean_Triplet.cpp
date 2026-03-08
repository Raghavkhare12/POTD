#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        const int MAX = 1000000;
        vector<bool> present(MAX + 1, false);

        for(int x : arr)
            present[x * x] = true;

        int n = arr.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int sum = arr[i]*arr[i] + arr[j]*arr[j];
                if(sum <= MAX && present[sum])
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    if(obj.pythagoreanTriplet(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}
/*Pythagorean Triplet
Difficulty: MediumAccuracy: 24.77%Submissions: 265K+Points: 4Average Time: 20m
Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

Examples:

Input: arr[] = [3, 2, 4, 6, 5]
Output: true
Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.
Input: arr[] = [3, 8, 5]
Output: false
Explanation: No such triplet possible.
Input: arr[] = [1, 1, 1]
Output: false
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 103
*/