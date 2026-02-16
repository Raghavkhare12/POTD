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