#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void traverse(TreeNode *root, vector<int>& inOrder)
{
    if(root == NULL)
        return;

    traverse(root -> left, inOrder);
    inOrder.push_back(root -> data);
    traverse(root -> right, inOrder);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> inOrder;
    traverse(root, inOrder);
    return inOrder;
}
