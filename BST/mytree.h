#ifndef MY_TREE
#define MY_TREE
#include <climits>

template<typename T> struct TreeNode {
    T value;
    TreeNode<T>* left = NULL;
    TreeNode<T>* right = NULL;
};

template<typename T> class Tree {
    private:
    TreeNode<T>* root;

    public:

    Tree();
    ~Tree();

    void in_order();
    void pre_order();
    void post_order();
    void insert(T val);
    bool in_tree(T val);
    int get_height();
    T get_min();
    T get_max();
    bool is_bst();
    void delete_value(T val);
};

#endif 