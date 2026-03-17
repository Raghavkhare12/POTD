#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// ---- Your Solution Class ----
class Solution {
public:

    Node* buildParent(Node* root, int target,
                      unordered_map<Node*, Node*>& parent) {

        queue<Node*> q;
        q.push(root);

        Node* targetNode = NULL;

        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();

            if(cur->data == target)
                targetNode = cur;

            if(cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            if(cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }

        return targetNode;
    }

    int minTime(Node* root, int target) {

        unordered_map<Node*, Node*> parent;
        Node* targetNode = buildParent(root, target, parent);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while(!q.empty()) {

            int size = q.size();
            bool burned = false;

            for(int i = 0; i < size; i++) {

                Node* cur = q.front();
                q.pop();

                if(cur->left && !visited[cur->left]) {
                    burned = true;
                    visited[cur->left] = true;
                    q.push(cur->left);
                }

                if(cur->right && !visited[cur->right]) {
                    burned = true;
                    visited[cur->right] = true;
                    q.push(cur->right);
                }

                if(parent[cur] && !visited[parent[cur]]) {
                    burned = true;
                    visited[parent[cur]] = true;
                    q.push(parent[cur]);
                }
            }

            if(burned) time++;
        }

        return time;
    }
};

// ---- MAIN FUNCTION ----
int main() {

    /*
        Example Tree:
                1
              /   \
             2     3
            / \     \
           4   5     6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int target = 5;

    Solution obj;
    int result = obj.minTime(root, target);

    cout << "Minimum time to burn tree: " << result << endl;

    return 0;
}
/*Burning Tree
Difficulty: HardAccuracy: 53.53%Submissions: 142K+Points: 8
Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

Note: The tree contains unique values.

Examples : 

Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
Input: root = [1, 2, 3, 4, 5, N, 7, 8, N, N, 10], target = 10

Output: 5
Explanation: Initially 10 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/