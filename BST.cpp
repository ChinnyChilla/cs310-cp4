#include "BST.h"


void BST::insertPrivate(Node*& node, const string& key, int value) {
    if (!node) {
        node = new Node(key, value);
    } else if (key < node->key) {
        insertPrivate(node->left, key, value);
    } else if (key > node->key) {
        insertPrivate(node->right, key, value);
    }
    
}


int BST::searchPrivate(Node* node, const string& key) const {
    if (!node) {
        return -1; 
    }
    if (key == node->key) {
        return node->value;
    } else if (key < node->key) {
        return searchPrivate(node->left, key);
    } else {
        return searchPrivate(node->right, key);
    }
}


void BST::clearPrivate(Node* node) {
    if (node) {
        clearPrivate(node->left);
        clearPrivate(node->right);
        delete node;
    }
}


void BST::insert(const string& key, int value) {
    insertPrivate(root, key, value);
}


int BST::search(const string& key) const {
    return searchPrivate(root, key);
}


void BST::clear() {
    clearPrivate(root);
    root = nullptr;
}


BST::~BST() {
    clear();
}
