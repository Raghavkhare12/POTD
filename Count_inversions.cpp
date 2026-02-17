#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long merge(vector<int> &arr, int left, int mid, int right){
        vector<int> temp;
        int i=left, j=mid+1;
        long long inv=0;
        while(i<=mid && j<=right){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
                inv+=(mid-i+1);
            }
        }
        while(i<=mid) temp.push_back(arr[i++]);
        while(j<=right) temp.push_back(arr[j++]);
        for(int k=left; k<=right;k++){
            arr[k]=temp[k-left];
        }
        return inv;
    }
    long long mergesort(vector<int> &arr, int left, int right){
        if(left>=right) return 0;
        int mid=left+(right-left)/2;
        long long inv=0;
        inv+=mergesort(arr, left, mid);
        inv+=mergesort(arr, mid+1, right);
        inv+=merge(arr, left, mid, right);
        return inv;
        
    }
    int inversionCount(vector<int> &arr) {
       return mergesort(arr, 0, arr.size()-1);
       }
};
int main(){
    vector<int> arr= {1, 4, 5, 1, 3, 6, 4};
    Solution obj;
    cout<<obj.inversionCount(arr);
    return 0;
}
/*Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 743K+Points: 4
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/
