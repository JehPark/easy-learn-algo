#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct s_node
{
    int data;
    t_node *left;
    t_node *right;
} t_node;

t_node *treeSearch(t_node *root, int data);
t_node *treeInsert(t_node *root, int data);

#endif