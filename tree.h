#ifndef LAB1_TREE_H
#define LAB1_TREE_H

#include <iostream>

class Tree {
    class Node {
    public:
        int value;
        Node* parent;
        Node* left = nullptr;
        Node* right = nullptr;

        Node(const int& val, Node* parent) : value(val), parent(parent) {};

    };
    Node* root;
public:
    Tree();
    Tree(const int&);
    ~Tree();

    void insert(const int&);
    void delete_tree(Node* root);

public:
    class iterator {
        Node* value;
    public:
        iterator(Node* val) : value(val) {};
        iterator() : value(nullptr) {};

        int operator* ();
        bool operator!= (const iterator&) const;
        bool operator== (const iterator&) const;
        iterator& operator++ ();
        iterator& operator-- ();
        iterator operator++ (int);
        iterator operator-- (int);
    };

public:
    iterator begin();
    iterator end();
};

#endif //LAB1_TREE_H
