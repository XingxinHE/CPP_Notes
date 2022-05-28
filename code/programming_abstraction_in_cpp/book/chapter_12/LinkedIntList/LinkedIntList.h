#ifndef _linkedintlist_h
#define _linkedintlist_h

#include <iostream>
#include "LinkNode.h"

using namespace std;

class LinkedIntList
{
  public:
    LinkedIntList();
    ~LinkedIntList();

    int size() const;
    int first() const;
    int last() const;
    bool isEmpty() const;
    bool contains(const int value) const;

    void addFront(const int value);
    void addBack(const int value);
    void addAfter(int refValue, int value);

    void removeFront();
    void removeBack();
    void removeValue(int value);

    void clear();

    friend ostream& operator<<(ostream &os, const LinkedIntList &list);

  private:
    int m_size;
    LinkNode *start;

    void release(LinkNode* startNode);

    LinkNode* search(LinkNode *startNode, const int value) const;
};

#endif