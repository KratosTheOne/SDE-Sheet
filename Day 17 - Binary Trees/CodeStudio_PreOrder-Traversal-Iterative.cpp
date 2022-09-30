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
vector<int> getPreOrderTraversal(TreeNode *root)
{
    stack<TreeNode*> st;
    vector<int> preOrder;

    if(root == NULL)
        return preOrder;

    st.push(root);

    while(!st.empty())
    {
        root = st.top();
        st.pop();
        preOrder.push_back(root -> data);

        if(root -> right)
            st.push(root -> right);
        if(root -> left)
            st.push(root -> left);
    }

    return preOrder;
}
