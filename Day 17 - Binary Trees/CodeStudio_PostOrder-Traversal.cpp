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

void traverse(TreeNode *root, vector<int>& PostOrder)
{
    if(root == NULL)
        return;

    traverse(root -> left, PostOrder);
    traverse(root -> right, PostOrder);
    PostOrder.push_back(root -> data);
}

vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> PostOrder;
    traverse(root, PostOrder);
    return PostOrder;
}
