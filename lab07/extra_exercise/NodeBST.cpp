//
// Created by Orsi on 11/4/2021.
//

#include "NodeBST.h"

NodeBST::NodeBST() {
    this->root = nullptr;
}

NodeBST::~NodeBST() {
    this->deleteSubTree(this->root);
    this->root = nullptr;
}

void NodeBST::insert(int val) {
    if(this->root == nullptr) {
        this->root = new Node;
        this->root->val = val;
        return;
    }

    if(find(val)) {
        return;
    }

    Node * newNode = new Node;
    newNode->val = val;

    Node * x = this->root;
    Node * y = nullptr;

    while(x != nullptr) {
        y = x;
        if(val < x->val) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    if (val < y->val) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }
}

bool NodeBST::find(int val) const {
    Node * temp = this->root;
    while(temp!= nullptr) {
        if(val > temp->val) {
            temp = temp->right;
        } else if (val < temp->val) {
            temp = temp->left;
        } else {
            return true;
        }
    }
    return false;
}

void NodeBST::print_inorder() const {
    this->inorder(this->root);
}

void NodeBST::print_preorder() const {
    this->preorder(this->root);
}

void NodeBST::print_postorder() const {
    this->postorder(this->root);
}

void NodeBST::inorder(NodeBST::Node *node) const {
    if(node != nullptr) {
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }
}

void NodeBST::preorder(NodeBST::Node *node) const {
    if(node == nullptr) {
        return;
    }

    cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void NodeBST::postorder(NodeBST::Node *node) const {
    if(node == nullptr){
        return;
    }

    postorder(node->left);
    postorder(node->right);

    cout << node->val << " ";
}

void NodeBST::deleteSubTree(NodeBST::Node *node) {
    if(node == nullptr) {
        return;
    }

    deleteSubTree(node->left);
    deleteSubTree(node->right);

    delete node;
}
