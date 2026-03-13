#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node *root) {
        
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int,int> mp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int hd = it.second;
            
            if(mp.find(hd) == mp.end())
                mp[hd] = node->data;
            
            if(node->left)
                q.push({node->left, hd - 1});
                
            if(node->right)
                q.push({node->right, hd + 1});
        }
        
        for(auto x : mp)
            ans.push_back(x.second);
            
        return ans;
    }
};

int main() {

    // Creating example tree
    /*
            10
           /  \
         20    30
        /  \   / \
      40   60 90 100
    */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->right->left = new Node(90);
    root->right->right = new Node(100);

    Solution obj;
    vector<int> result = obj.topView(root);

    cout << "Top View: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}
/*Top View of Binary Tree
Difficulty: MediumAccuracy: 38.43%Submissions: 438K+Points: 4Average Time: 45m
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.


Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/