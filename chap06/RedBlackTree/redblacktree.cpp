#include "redblacktree.h"

bool red(Node *node)
{
    if (node == NULL)
        return false;
    return node->color == RED;
}

void colorFlip(Node *node)
{
    node->color = node->color ^ 1;
    node->left->color = node->left->color ^ 1;
    node->right->color = node->right->color ^ 1;
}

Node *leftRotate(Node *node)
{
    Node *temp = node->right;
    node->right = temp->left;
    temp->left = node;

    temp->color = node->color;
    node->color = RED;
    return temp;
}

Node *rightRotate(Node *node)
{
    Node *temp = node->left;
    node->left = temp->right;
    temp->right = node;

    temp->color = node->color;
    node->color = RED;
    return temp;
}

Node* rotate(Node *node,bool dir) /// direction : left / right
{
    Node *temp = node->child[!dir];
    node->child[!dir] = temp->child[dir];
    temp->child[dir] = node;

    temp->color = node->color;
    node->color = RED;

    return temp;
}

Node* doubleRotate(Node *node,bool dir) /// align reds  , then rotate
{
    node->child[!dir] = rotate(node->child[!dir],!dir);
    return rotate(node,dir);
}

void insert(int data)
{
    root = __insert(root, data);
    root->color = BLACK;
}

Node *__insert(Node *node, int data)
{
    if (node == NULL)
        return new Node(data, RED);
    bool dir = data > node->data;
    node->child[dir] = __insert(node->child[dir], data);
    return INSERT_FIX_UP(node, dir);
}

Node *INSERT_FIX_UP(Node *node, bool dir)
{
    if (red(node->child[dir]))
    {
        if (red(node->child[dir]->child[dir]) || red(node->child[dir]->child[!dir]))
            colorFlip(node);
    }
    else
    {
        if (red(node->child[dir]->child[dir]))
            node = rotate(node, !dir);
        else if (red(node->child[dir]->child[!dir]))
            node = doubleRotate(node, !dir);
    }
    return node;
}

void delete_(int data)
{
    bool ok = false;
    root = __delete(root,data,ok);
    if(root!=NULL) root->color = BLACK;
}

Node* __delete(Node *node,int data,bool &ok)
{
    if(node == NULL)
    {
        ok = true;
        return;
    }

    /// found the delete key
    if(node->data == data)
    {
        /// has one or less child
        if(node->child[left]==NULL || node->child[right]==NULL)
        {
            Node* temp = NULL;
            if(node->child[left]) temp = node->child[left];
            if(node->child[right]) temp = node->child[right];

            if(red(node)) /// the node is red => just delete it
            {
                free(node);
                ok = true;
            }
            else if(red(temp)) /// only child is red => replace with that red child and recolor black . so , black balance restored
            {
                temp->color = BLACK;
                free(node);
                ok = true;
            }

            return temp;
        }
        else /// has 2 child => replace with inorder predecessor / successor and recurse for that
        {
            Node *temp = getMax(node->child[left]); /// inorder predecessor : maximum value in the left subtree

            node->data = temp->data;
            data = temp->data; /// updating with predecessor data as this is the one to delete now
        }
    }


    bool dir = data > node->data;

    node->child[dir] = __delete(node->child[dir],data,ok); /// recurse
    
    return ok ? node : DELETE_FIX_UP(node,dir,ok);
}

Node* DELETE_FIX_UP(Node *node,bool dir, bool &ok)
{
    Node *parent = node; /// saving for later red sibling fixing case
    Node *sibling = node->child[!dir];

    /// Red Sibling Case => Reduce to Black Sibling Case
    if(red(sibling))
    {
        node = rotate(node,dir);
        sibling = parent->child[!dir];
    }

    if(sibling != NULL)
    {
        /// Black Sibling Case , Part 1 : Black Sibling with only black children
        if(!red(sibling->child[left]) && !red(sibling->child[right]))
        {
            if(red(parent)) ok = true; /// will color it black and sibling subtree will not have imbalance

            parent->color = BLACK; /// if not ok , we proceed further
            sibling->color = RED;
        }
        else /// Black Sibling Case , Part 2 : Black Sibling with not red children
        {

            int initcol_parent = parent->color;
            bool isRedSiblingReduction = !(node==parent);

            if(red(sibling->child[!dir])) /// RR , LL
            {
                parent = rotate(parent,dir); /// single rotation
            }
            else
            {
                parent = doubleRotate(parent,dir); /// align and rotate
            }

            parent->color = initcol_parent; /// color will be the same as initial parent
            parent->child[left]->color = BLACK;
            parent->child[right]->color = BLACK;

            if(isRedSiblingReduction)
            {
                node->child[dir] = parent; /// fixing the child for proper bottom up fixing later
            }
            else
            {
                node = parent; /// usual black case
            }

            ok = true;
        }
    }

    return node;
}