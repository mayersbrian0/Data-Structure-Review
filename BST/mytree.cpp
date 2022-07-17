#include <iostream>
#include "mytree.h"

template<typename T> Tree<T>::Tree() {
    root = NULL;
}

template<typename T> Tree<T>::~Tree() {
    while (root) delete_value(root->value);
}

template<typename T> void in_order_helper(TreeNode<T>* root) {
    if (root == NULL) return;
    in_order_helper(root->left);
    std::cout << root->value << " ";
    in_order_helper(root->right);
}

template<typename T> void Tree<T>::in_order() {
    in_order_helper(root);
    std::cout << "\n";
}

template<typename T> void pre_order_helper(TreeNode<T>* root) {
    if (root == NULL) return;
    std::cout << root->value << " ";
    pre_order_helper(root->left);
    pre_order_helper(root->right);
}

template<typename T> void Tree<T>::pre_order() {
    pre_order_helper(root);
    std::cout << "\n";
}

template<typename T> void post_order_helper(TreeNode<T>* root) {
    if (root == NULL) return;
    post_order_helper(root->left);
    post_order_helper(root->right);
    std::cout << root.value << "\n";
}

template<typename T> void Tree<T>::post_order() {
    post_order_helper(root);
    std::cout << "\n";
}

template<typename T> TreeNode<T>* insert_helper(TreeNode<T>*& root, T value) {
    if (root == NULL) {
        TreeNode<T>* new_node = new TreeNode<T>;
        new_node->value = value;
        root = new_node;
        return new_node;
    }

    else {
        if (root->value >= value) {
            root->left = insert_helper(root->left, value);
        }
        else {
            root->right = insert_helper(root->right, value);
        }
    }

    return root;
}

template<typename T> void Tree<T>::insert(T value) {
    insert_helper(root, value);
}

template<typename T> bool in_tree_helper(TreeNode<T>* root, T value) {
    if (root == NULL) return false;
    else if (root->value == value) return true;
    
    return in_tree_helper(root->left, value) || in_tree_helper(root->right, value);
}

template<typename T> bool Tree<T>::in_tree(T value) {
    return in_tree_helper(root, value);
}

template<typename T> int get_height_helper(TreeNode<T>* root) {
    if (root == NULL) return 0;
    return std::max(get_height_helper(root->left) +1, get_height_helper(root->right) +1);
}

template<typename T> int Tree<T>::get_height() {
    return get_height_helper(root);
}

template<typename T> T get_minmax_helper(TreeNode<T>* root, bool min) {
    if ( (min && root->left == NULL) || (!min && root->right == NULL)) return root->value;
    TreeNode<T>* param = min ? root->left : root->right;
    return get_minmax_helper(param, min);
}

template<typename T> T Tree<T>::get_min() {
    if (root == NULL) {
        std::cout << "Error Empty Tree\n";
        return INT_MIN;
    }
    return get_minmax_helper(root, true);
}

template<typename T> T Tree<T>::get_max() {
    if (root == NULL) {
        std::cout << "Error Empty Tree\n";
        return INT_MIN;
    }
    return get_minmax_helper(root, false);
}

template<typename T> bool is_bst_helper(TreeNode<T>* root, long min, long max) {
    if (root == NULL) return true;
    else if (root->value <= min || root->value >= max) return false;
    //the current nodes value becomes the min/max for the subproblems
    return is_bst_helper(root->left, min, root->value) && is_bst_helper(root->right, root->value, max);
}

template<typename T> bool Tree<T>::is_bst() {
    return is_bst_helper(root, LONG_MIN, LONG_MAX);
}


template<typename T> TreeNode<T>* get_leftmost(TreeNode<T>* root) {
    TreeNode<T>* temp = root;
    while (temp && temp->left != NULL) temp = temp->left;
    return temp;
}

template<typename T> TreeNode<T>* delete_value_helper(TreeNode<T>*& root, T value, bool& found) {
    if (root == NULL) return NULL;

    if (root->value == value) {
        found = true;
        TreeNode<T>* temp;
        //leaf node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        else if (root->right == NULL || root->left == NULL) {
            temp = (root->right) ? root->right : root->left;
            delete root;
            return temp;
        }

        //if both sides have values
        //find the leftmost on the right side to replace it
        temp = get_leftmost(root->right);
        root->value = temp->value;
        root->right = delete_value_helper(root->right, temp->value,found);
    }

    else if (root->value > value) root->left = delete_value_helper(root->left, value, found);
    else root->right = delete_value_helper(root->right, value, found);

    return root;
}

template<typename T> void Tree<T>::delete_value(T value) {
    if (root == NULL) {
        std::cout << "Error Empty Tree\n";
        return;
    }

    bool is_found = false;
    root = delete_value_helper(root, value, is_found);

    if (!is_found) std::cout << "Value DNE in Tree\n";
}