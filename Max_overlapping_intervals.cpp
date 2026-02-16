#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
         int n= arr.size();
         vector<int> start(n), end(n);
         for(int i=0; i<n; i++){
             start[i]= arr[i][0];
             end[i]= arr[i][1];
         }
         sort(start.begin(), start.end());
         sort(end.begin(), end.end());
         
         int i=0, j=0;
         int current=0, ans=0;
         
         while(i<n && j<n){
             if(start[i]<=end[j]){
                 current++;
                 ans=max(ans, current);
                 i++;
             }
             else{
                 current--;
                 j++;
             }
         }
         return ans;
    }
};
int main(){
    vector<vector<int>> arr={{1,5}, {5,8}, {4,8}};
    Solution obj;
    cout<<obj.overlapInt(arr);
    return 0;
}

/*Maximum number of overlapping Intervals
Difficulty: HardAccuracy: 34.79%Submissions: 5K+Points: 8
You are given an array of intervals arr[][], where each interval is represented by two integers [start, end] (inclusive). Return the maximum number of intervals that overlap at any point in time.

Examples :

Input: arr[][] = [[1, 2], [2, 4], [3, 6]]
Output: 2
Explanation: The maximum overlapping intervals are 2(between (1, 2) and (2, 4) or between (2, 4) and (3, 6))
 
Input: arr[][] = [[1, 8], [2, 5], [5, 6], [3, 7]]
Output: 4
Explanation: The maximum overlapping intervals are 4 (between (1, 8), (2, 5), (5, 6) and (3, 7))
Constraints:
2 ≤ arr.size() ≤ 2 * 104
1 ≤ arr[i][0] < arr[i][1] ≤ 4*106
*/
