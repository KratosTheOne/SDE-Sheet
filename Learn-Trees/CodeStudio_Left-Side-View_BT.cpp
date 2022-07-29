/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void recursion(BinaryTreeNode<int>* root, int level, int *lev)
{
    if(root == NULL) return;
    if(*lev == level)
    {
        cout << root -> data << " ";
        (*lev)++;
    }
    recursion(root -> left, level + 1, lev);
    recursion(root -> right, level + 1, lev);
}

void printLeftView(BinaryTreeNode<int> *root)
{
    int lev = 0;

    recursion(root, 0, &lev);
}
