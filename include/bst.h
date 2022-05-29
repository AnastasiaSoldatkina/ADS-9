// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template <typename T>
class BST {

private:
    struct Node {
        T value;
        int count = 0;
        Node* left = nullptr, * right = nullptr;
    };
    Node* root;

    Node* addNode(Node* root, const T& val) {
        if (root == nullptr) {
            root = new Node;
            root->value = val;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (val > root->value) {
            root->left = addNode(root->left, val);
        } else if (val < root->value) {
            root->right = addNode(root->right, val);
        } else {
            root->count++;
        }
        return root;
    }
    int searchNode(Node* root, const T& val) {
        if (root == nullptr) {
            return 0;
        } else if (root->value == val) {
            return root->count;
        } else if (root->value > val) {
            return searchNode(root->right, val);
        } else {
            return searchNode(root->left, val);
        }
    }
    int depth_p(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int lt = depth_p(root->left);
        int rt = depth_p(root->right);
        if (lt > rt) {
            return lt + 1;
        } else {
            return rt + 1;
        }
    }

public:
    BST() : root(nullptr) {}
    void add(const T& val) {
        root = addNode(root, val);
    }
    int search(const T & val) {
        return searchNode(root, val);
    }
    int depth() {
        return depth_p(root);
    }
};
#endif  // INCLUDE_BST_H_
