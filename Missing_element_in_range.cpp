#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> output;
        for(int i=low; i<=high; i++){
            if(s.find(i)==s.end()){
                output.push_back(i);
            }
        }
        return output;
    }
};
int main(){
    vector<int> arr = {1, 4, 5, 1, 3, 6, 4};
    int low = 2;
    int high = 8;
    Solution obj;
    vector<int> result = obj.missinRange(arr, low, high); 
    for(int x : result){
        cout << x << " ";
    }
    return 0;
}
/*
BRUTE FORCE APPROACH
class Solution {
  public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<int> output;
        for(int i=low;i<=high;i++){
            bool found=false;
            for(int j=0; j<arr.size();j++){
                if(arr[j]==i){
                    found=true;
                }
            }
            if(!found){
                output.push_back(i);
            }
            
        }
        return output;
        
    }
};
*/
/*
Missing Element in Range
Difficulty: MediumAccuracy: 50.89%Submissions: 2K+Points: 4Average Time: 20m
Given an array arr[] of distinct integers and a range [low, high], find all the numbers within the range that are not present in the array. return the missing numbers in sorted order.

Examples:

Input: arr[] = [10, 12, 11, 15], low = 10, high = 15
Output: [13, 14]
Explaination: Numbers 13 and 14 lie in the range [10, 15] but are not present in the array.
Input: arr[] = [1, 4, 11, 51, 15], low = 50, high = 55
Output: [52, 53, 54, 55]
Explaination: Numbers 52, 53, 54 and 55 lie in the range but [50, 55] but are not present in the array.
Constraints:
1 ≤ arr.size(), low, high ≤ 105
1 ≤ arr[i] ≤ 105
*/
