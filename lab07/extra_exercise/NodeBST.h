//
// Created by Orsi on 11/4/2021.
//

#ifndef EXTRA_EXERCISE_NODEBST_H
#define EXTRA_EXERCISE_NODEBST_H

#include "BST.h"
#include <iostream>

using namespace std;

class NodeBST : public BST
{
    struct Node
    {
        int val;
        Node *left, *right;
        Node(int val = 0, Node *left = nullptr, Node *right = nullptr):val(val),
                                                                       left(left), right(right) {}
    };
    Node *root;
    // Helper functions for travelsals
    void inorder(Node *node) const;
    void preorder(Node *node) const;
    void postorder(Node *node) const;
    // Helper function for destructor
    void deleteSubTree(Node *node);
public:
    NodeBST();
    virtual ~NodeBST();
    void insert(int val);
    bool find(int val) const;
    void print_inorder() const;
    void print_preorder() const;
    void print_postorder() const;
};

#endif //EXTRA_EXERCISE_NODEBST_H
