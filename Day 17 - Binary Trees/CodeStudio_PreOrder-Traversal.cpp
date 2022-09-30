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

void traverse(TreeNode *root, vector<int>& preOrder)
{
    if(root == NULL)
        return;

    preOrder.push_back(root -> data);
    traverse(root -> left, preOrder);
    traverse(root -> right, preOrder);
}

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> preOrder;
    traverse(root, preOrder);
    return preOrder;
}
