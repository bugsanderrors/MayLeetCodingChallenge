/*
    In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

    Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

    We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

    Return true if and only if the nodes corresponding to the values x and y are cousins.

    Example 1:
    Input: root = [1,2,3,4], x = 4, y = 3
    Output: false

    Example 2:
    Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
    Output: true

    Example 3:
    Input: root = [1,2,3,null,4], x = 2, y = 3
    Output: false
    
    Note:
        * The number of nodes in the tree will be between 2 and 100.
        * Each node has a unique integer value from 1 to 100.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,TreeNode*> m;
        m[x]=root;
        m[y]=root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                if(temp->left->val==x)
                    m[x]=temp;
                else if(temp->left->val==y)
                    m[y]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                if(temp->right->val==x)
                    m[x]=temp;
                else if(temp->right->val==y)
                    m[y]=temp;
                q.push(temp->right);
            }
        }
        unordered_map<int,int> m2;
        int level=0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            level++;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==x)
                    m2[x]=level;
                else if(temp->val==y)
                    m2[y]=level;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return m2[x]==m2[y] && m[x]!=m[y];
    }
};