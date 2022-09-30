#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void traversalInorder(BinaryTreeNode<int> *root, vector<int>& inorder)
{
    if(root == NULL)
        return;

    traversalInorder(root -> left, inorder);
    inorder.push_back(root -> data);
    traversalInorder(root -> right, inorder);
}

void traversalPreorder(BinaryTreeNode<int> *root, vector<int>& preorder)
{
    if(root == NULL)
        return;

    preorder.push_back(root -> data);
    traversalPreorder(root -> left, preorder);
    traversalPreorder(root -> right, preorder);
}

void traversalPostorder(BinaryTreeNode<int> *root, vector<int>& postorder)
{
    if(root == NULL)
        return;

    traversalPostorder(root -> left, postorder);
    traversalPostorder(root -> right, postorder);
    postorder.push_back(root -> data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){

    vector<vector<int>> treeTraversals;
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    traversalInorder(root, inorder);
    treeTraversals.push_back(inorder);

    traversalPreorder(root, preorder);
    treeTraversals.push_back(preorder);

    traversalPostorder(root, postorder);
    treeTraversals.push_back(postorder);

    return treeTraversals;
}
