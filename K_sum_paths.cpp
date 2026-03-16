#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:

    int dfs(Node* root, long long currSum, int k, unordered_map<long long,int>& mp) {
        if(root == NULL)
            return 0;

        currSum += root->data;

        int count = mp[currSum - k];

        mp[currSum]++;

        count += dfs(root->left, currSum, k, mp);
        count += dfs(root->right, currSum, k, mp);

        mp[currSum]--; // backtrack

        return count;
    }

    int countAllPaths(Node* root, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;

        return dfs(root, 0, k, mp);
    }
};

int main() {

    /*
            8
           / \
          4   5
         / \   \
        3   2   2
       / \   \
      3  -2   1
    */

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);

    root->left->left = new Node(3);
    root->left->right = new Node(2);

    root->right->right = new Node(2);

    root->left->left->left = new Node(3);
    root->left->left->right = new Node(-2);

    root->left->right->right = new Node(1);

    int k = 7;

    Solution obj;
    cout << "Number of paths = " << obj.countAllPaths(root, k);

    return 0;
}
/*K Sum Paths
Difficulty: MediumAccuracy: 44.73%Submissions: 142K+Points: 4
Given the root of a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k.

Note: A path can start and end at any node within the tree but must always move downward (from parent to child).

Examples:

Input: root = [8, 4, 5, 3, 2, N, 2, 3, -2, N, 1], k = 7

Output: 3
Explanation: The following paths sum to k
 
Input: root = [1, 2, 3], k = 3

Output: 2 
Explanation: The following paths sum to k

Constraints:
1 ≤ number of nodes ≤ 104
-100 ≤ node value ≤ 100
-109 ≤ k ≤ 109
*/