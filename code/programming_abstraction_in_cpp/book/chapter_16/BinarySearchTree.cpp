#include "BinarySearchTree.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree()
                :m_root(nullptr), m_count(0)
{}

BinarySearchTree::~BinarySearchTree()
{
    deleteRec(m_root);
}

int BinarySearchTree::findMin() const
{
    TreeNode *prev = nullptr;
    TreeNode *start = m_root;
    while (start != nullptr)
    {
        prev = start;
        start = start->LNode;
    }
    if (prev != nullptr)
    {
        return prev->value;
    }
    else
    {
        throw std::out_of_range("The binary tree is empty");
    }
}

int BinarySearchTree::findMax() const
{
    TreeNode *prev = nullptr;
    TreeNode *start = m_root;
    while (start != nullptr)
    {
        prev = start;
        start = start->RNode;
    }
    if (prev != nullptr)
    {
        return prev->value;
    }
    else
    {
        throw std::out_of_range("The binary tree is empty");
    }

}

void BinarySearchTree::add(int value)
{
    addRec(m_root, value);
}

void BinarySearchTree::addRec(TreeNode *node, int value)
{
    if(node == nullptr)
    {
        node = new TreeNode(value);
    }
    else
    {
        if(value < node->value)
        {
            addRec(node->LNode, value);
        }
        else if(value == node->value)
        {
            return;
        }
        else
        {
            addRec(node->RNode, value);
        }
    }
}

bool BinarySearchTree::contains(int value) const
{
    return containsRec(m_root, value);
}

bool BinarySearchTree::containsRec(TreeNode *node, int value) const
{
    if (node == nullptr)
    {
        return false;
    }
    else
    {
        if(value == node->value)
        {
            return true;
        }
        else if(value < node->value)
        {
            return containsRec(node->LNode, value);
        }
        else
        {
            return containsRec(node->RNode, value);
        }
    }
}

string BinarySearchTree::toString() const
{
    return toString(m_root);
}

string BinarySearchTree::toString(TreeNode *node) const
{
    if(node == nullptr)
    {
        return "";
    }
    string output = "";
    output += toString(node->LNode);
    output += node->value;
    output += toString(node->RNode);
    return output;
}

void BinarySearchTree::deleteRec(TreeNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    else
    {
        deleteRec(node->LNode);
        deleteRec(node->RNode);
        delete node;
    }
    
}

ostream & operator<<(ostream &os, const BinarySearchTree &bTree)
{
    string output = bTree.toString();
    os << output << endl;
    return os;
}



