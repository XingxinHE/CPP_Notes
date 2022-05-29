#ifndef _linkedintlist_h
#define _linkedintlist_h

#include <iostream>
#include "LinkNode.h"

using namespace std;

class LinkedIntList
{
  public:
/*  Constructir  */
    LinkedIntList();

/*  Destructor  */
    ~LinkedIntList();

/*  Constness Functions  */
    int size() const;
    int first() const;
    int last() const;
    bool isEmpty() const;
    bool contains(const int value) const;

/*  Addition Functions  */
    void addFront(const int value);
    void addBack(const int value);
    void addAfter(int refValue, int value);

/*  Remove Functions  */
    void removeFront();
    void removeBack();
    void removeAfter(LinkNode* node);
    void removeValue(int value);
    bool removeValueMarty(int value);
    void clear();

/*  ToString Function  */
    friend ostream& operator<<(ostream &os, const LinkedIntList &list);

  private:
/*  Private Members  */
    int m_size;
    LinkNode *start;

/*  Private Function  */
    void release(LinkNode *&startNode);
    LinkNode* search(LinkNode *startNode, const int value) const;
    void search(LinkNode *&prevNode, LinkNode *&startNode, const int value);
};

#endif
