#include "tree.h"

Tree::Tree() {
    root = new Node(1, nullptr);
}

Tree::Tree(const int& val) {
    root = new Node(val, nullptr);
}

void Tree::delete_tree(Node *root) {
    if (root->left) delete_tree(root->left);
    if (root->right) delete_tree(root->right);
    delete root;
}

Tree::~Tree() {
    delete_tree(root);
}

void Tree::insert(const int& val) {
    Node* tmp = root;
    while (tmp) {
        if (val < tmp->value) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                Node* ins = new Node(val, tmp);
                tmp->left = ins;
                return;
            }
        } else {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                Node* ins = new Node(val, tmp);
                tmp->right = ins;
                return;
            }
        }
    }
}

Tree::iterator Tree::begin() {
    Node* tmp = root;
    while (tmp->left || tmp->right) {
        tmp = tmp->left ? tmp->left : tmp->right;
    }
    return iterator(tmp);
}

Tree::iterator Tree::end() {
    return iterator(root);
}

int Tree::iterator::operator*() {
    return value->value;
}

bool Tree::iterator::operator!= (const Tree::iterator& it) const {
    return value != it.value;
}

bool Tree::iterator::operator== (const Tree::iterator& it) const {
    return value == it.value;
}

Tree::iterator& Tree::iterator::operator++ () {
    if (value->parent == nullptr)
        value = nullptr;
    else if (value->parent->right == value)
        value = value->parent;
    else {
        value = value->parent;
        if (value->right != nullptr) {
            value = value->right;
            while (value->left || value->right) {
                value = value->left ? value->left : value->right;
            }
        }
    }
    return *this;
}

Tree::iterator& Tree::iterator::operator-- () {
    if (value->right != nullptr)
        value = value->right;
    else if (value->left != nullptr)
        value = value->left;
    else {
        Node *tmp = value;
        while (tmp->parent != nullptr) {
            if (tmp->parent->left != nullptr && tmp->parent->left != tmp) {
                value = tmp->parent->left;
                break;
            }
            tmp = tmp->parent;
        }
    }
    return *this;
}

Tree::iterator Tree::iterator::operator++ (int) {
    Node* tmp = value;
    if (value->parent == nullptr)
        value = nullptr;
    else if (value->parent->right == value)
        value = value->parent;
    else {
        value = value->parent;
        if (value->right != nullptr) {
            value = value->right;
            while (value->left || value->right) {
                value = value->left ? value->left : value->right;
            }
        }
    }
    return iterator(tmp);
}

Tree::iterator Tree::iterator::operator-- (int) {
    Node* _tmp = value;
    if (value->right != nullptr)
        value = value->right;
    else if (value->left != nullptr)
        value = value->left;
    else {
        Node *tmp = value;
        while (tmp->parent != nullptr) {
            if (tmp->parent->left != nullptr && tmp->parent->left != tmp) {
                value = tmp->parent->left;
                break;
            }
            tmp = tmp->parent;
        }
    }
    return iterator(_tmp);
}
