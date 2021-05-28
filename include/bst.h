// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {

 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };

 private:
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
    void delTree(Node*);
    void printTree(Node*);
    Node* delNode(Node*, int);

 public:
    BST();
    ~BST();
    void add(T);
    int depth();
    int search(T);
    void print();
    void clear();
    void remove(int);
};
template <typename T>
BST<T>::BST():root(nullptr) {}

template <typename T>
BST<T>::~BST() {
    if (root)
        delTree(root);
}

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    }
    else if (root->value > value) {
        root->left = addNode(root->left, value);
    }
    else if (root->value < value) {
        root->right = addNode(root->right, value);
    }
    else
        root->count++;
    return root;
}

template <typename T>
void BST<T>::add(T value) {
    root = addNode(root, value);
}

template <typename T>
void BST<T>::printTree(Node* root) {
    if (root == nullptr)
        return;
    printTree(root->left);
    for (int i = 0; i < root->count; i++)
        std::cout << root->value << " ";
    printTree(root->right);
}

template <typename T>
void BST<T>::print() {
    printTree(root);
}

template <typename T>
void BST<T>::delTree (Node* root) {
    if (root == nullptr) {
        return;
    }
    else {
        delTree(root->left);
        delTree(root->right);
        delete root;
    }
}

template <typename T>
void BST<T>::clear() {
    if (root) {
        delTree(root);
        root = nullptr;
    }
}

template <typename T>
void BST<T> ::remove(int value) {
    if (root)
        root = delNode(root, value);
}

template <typename T>
typename BST<T>::Node* BST<T>::delNode(typename BST<T>::Node* root, int value) {
    Node* p, * v;
    if (root == nullptr)
        return root;
    else if (value < root->value)
        root->left = delNode(root->left, value);
    else if (value > root->value)
        root->right = delNode(root->right, value);
    else {
        p = root;
        if (root->right == nullptr)
            root = root->left;
        else if (root->left == nullptr)
            root = root->right;
        else {
            v = root->left;
            if (v->right) {
                while (v->right->right)
                    v = v->right;
                root->value = v->right->value;
                root->count = v->right->count;
                p = v->right;
                v->right = v->right->left;
            }
            else {
                root->value = v->value;
                root->count = v->count;
                p = v;
                root->left = root->left->left;
            }
        }
        delete p;
    }
    return root;
}

template <typename T>
void BST<T>::remove(int value) {
    if (root)
        root = delNode(root, value);
}

template <typename T>
int depthTree(Node* root) {
    if (root == nullptr)
        return;
    int leftH = depthTree(root->left);
    int rightH = depthTree(root->right);
    return ((leftH > rightH) ? leftH : rightH) + 1;
}

template <typename T>
int depth() {
    return depthTree(root) - 1;
}

template <typename T>
int searchNode(Node* root, T v) {
    if (root == nullptr)
        return 0;
    else if (root->value == v)
        return root->count;
    else if (root->value > v)
        return (searchNode(root->left, v));
    else return (searchNode(root->right, v));
}

template <typename T>
int search(T v) {
    return searchNode(root, v);
}

#endif  // INCLUDE_BST_H_

