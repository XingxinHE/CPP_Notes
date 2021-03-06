#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <string>

class BinarySearchTree
{

public:
    BinarySearchTree();
    ~BinarySearchTree();

    int findMin() const;
    int findMax() const;
    bool contains(int value) const;
    void add(int value);
    void remove(int value);
    std::string toString() const;
    friend std::ostream& operator<<(std::ostream &os, const BinarySearchTree &bTree);


private:

    struct TreeNode
    {
        int value;
        TreeNode *LNode;
        TreeNode *RNode;
        TreeNode(int _value)
                :value(_value), LNode(nullptr), RNode(nullptr)
        {}
    };

    TreeNode *m_root;
    int m_count;

    void deleteRec(TreeNode *node);
    void addRec(TreeNode *&node, int value);
    bool containsRec(TreeNode *node, int value) const;
    std::string toString(TreeNode *node) const;
    void findNodeRec(TreeNode *&prev, TreeNode *&curr, int value);
    bool isLeaf(TreeNode *node) const;
    bool isTree(TreeNode *node) const;

    TreeNode* findMin(TreeNode *node) const;
    TreeNode* findMax(TreeNode *node) const;
    
    
};

#endif
