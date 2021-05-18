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
    t_node *newNode = new t_node();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
        root = newNode;
    else
    {
        t_node *tmp = root;
        t_node *parent = NULL;
        while (tmp != NULL)
        {
            parent = root;
            if (root->data > data)
                tmp = root->left;
            else
                tmp = root->right;
        }
        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    return (root);
}

void deletion(t_node *root, t_node *target, t_node *parent)
{
    treeDelete(root, target, parent);
    if (!(target->left && target->right))
        delete target;
}

void treeDelete(t_node *root, t_node *target, t_node *parent)
{
    if (root == target)
        root = deleteNode(target);
    else if (target == parent->left)
        parent->left = deleteNode(target);
    else
        parent->right = deleteNode(target);
}

t_node *deleteNode(t_node *target)
{
    if (target->left == NULL && target->right == NULL)
        return (NULL);
    else if (target->left == NULL && target->right != NULL)
        return (target->right);
    else if (target->left != NULL && target->right == NULL)
        return (target->left);
    else
    {
        t_node *mleft = target->right;
        t_node *parent = target;
        while (mleft->left != NULL)
        {
            parent = mleft;
            mleft = mleft->left;
        }
        target->data = mleft->data;
        if (mleft == target->right)
            target->right = mleft->right;
        else
            parent->left = mleft->right;
        delete mleft;
        return (target);
    }
}