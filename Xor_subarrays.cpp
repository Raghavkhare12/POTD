//Using HashMap O(n) not Brute Force O(n^2)
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n=arr.size();
        int xorsum=0;
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            xorsum^=arr[i];
            
            if(xorsum==k) count++;
            if(mp.find(xorsum ^k)!= mp.end()){
                count+=mp[xorsum ^ k];
            }
            mp[xorsum]++;
        }
        return count;
    }
};
int main(){
    vector<int> arr={12, 2, 1, 3, 5, 6, 7, 8, 9};
    int k=6;
    Solution obj;
    cout<<obj.subarrayXor(arr, k);
    return 0;
}
/*Count Subarrays with given XOR
Difficulty: MediumAccuracy: 58.86%Submissions: 74K+Points: 4
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Note: It is guranteed that the total count will fit within a 32-bit integer.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
0 ≤ k ≤ 105
*/