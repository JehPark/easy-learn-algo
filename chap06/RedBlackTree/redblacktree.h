#ifndef BINARYTREE_H
#define BINARYTREE_H

#define left 0
#define right 1
#define RED 0
#define BLACK 1

struct Node
{
    int data, color;
    Node *child[2];

    Node(int data, int color)
    {
        this->data = data;
        this->color = color;
        this->child[left] = NULL;
        this->child[right] = NULL;
    }
};

#endif