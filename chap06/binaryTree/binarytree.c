#include "binarytree.h"

t_node *treeSearch(t_node *root, int data)
{
    if (root == NULL || root->data == data)
        return (root);
    if (data < root->data)
        return (treeSearch(root->left, data));
    else
        return (treeSearch(root->right, data));
}

t_node *treeInsert(t_node *root, int data)
{
    if (root == NULL)
    {
        t_node *newNode;
        newNode = new t_node();
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return (newNode);
    }
    if (root->data > data)
        root->left = treeSearch(root->left, data);
    else
        root->right = treeSearch(root->right, data);
    return (root);
}

t_node *treeInsertIter(t_node *root, int data)
{
}