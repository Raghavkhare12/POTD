#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Solution class (your code)
class Solution {
public:
    int ans = 0;

    struct Info {
        int size;
        int min;
        int max;
        bool isBST;
    };

    Info solve(Node* root) {
        if (!root) return {0, INT_MAX, INT_MIN, true};

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;
        curr.size = left.size + right.size + 1;

        if (left.isBST && right.isBST &&
            root->data > left.max &&
            root->data < right.min) {

            curr.min = min(root->data, left.min);
            curr.max = max(root->data, right.max);
            curr.isBST = true;

            ans = max(ans, curr.size);
        } else {
            curr.isBST = false;
        }

        return curr;
    }

    int largestBst(Node *root) {
        ans = 0;
        solve(root);
        return ans;
    }
};

// -------- MAIN FUNCTION --------
int main() {
    /*
        Example Tree:
                5
               / \
              2   4
             / \
            1   3
    */

    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution obj;
    cout << "Largest BST size: " << obj.largestBst(root) << endl;

    return 0;
}
/*Largest BST
Difficulty: MediumAccuracy: 29.73%Submissions: 196K+Points: 4Average Time: 40m
You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

Examples :

Input: root = [5, 2, 4, 1, 3]
Root-to-leaf-path-sum-equal-to-a-given-number-copy
Output: 3
Explanation:The following sub-tree is a BST of size 3
Balance-a-Binary-Search-Tree-3-copy
Input: root = [6, 7, 3, N, 2, 2, 4]

Output: 3
Explanation: The following sub-tree is a BST of size 3:

Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/