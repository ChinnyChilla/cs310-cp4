#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

struct Node {
    std::string key; 
    int value;       
    Node* left;
    Node* right;

    Node(string key, int value) {
        key = key; 
        value = value; 
        left = nullptr; 
        right = nullptr;
    }
};


class BST {
private:
    Node* root;

    void insertPrivate(Node*& node, const string& key, int value);
    int searchPrivate(Node* node, const string& key) const;
    void clearPrivate(Node* node);

public:
    BST(){ 
        root = nullptr;
    }
    ~BST();

    void insert(const string& key, int value);
    int search(const string& key) const;
    void clear();
    
};

#endif 

