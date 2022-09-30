Untitled10/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findDia(TreeNode<int> *root, int& d)
{
    if(root == NULL) return 0;

    int lh = findDia(root -> left, d);
    int rh = findDia(root -> right, d);

    d = max(d, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    int dia = 0;
    findDia(root, dia);
    return dia;
}

