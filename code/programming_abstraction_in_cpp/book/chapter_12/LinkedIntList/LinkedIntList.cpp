#include <stdexcept>
#include "LinkedIntList.h"


LinkedIntList::LinkedIntList()
              :m_size(0), start(nullptr)
{
}

LinkedIntList::~LinkedIntList()
{
    if (start != nullptr)
    {
        release(start);
    }
}

int LinkedIntList::size() const
{
    return m_size;
}

int LinkedIntList::first() const
{
    if (!isEmpty())
    {
        return start->value;
    }
    else
    {
        throw std::invalid_argument("The LinkedList is empty!");
    }
}

int LinkedIntList::last() const
{
    LinkNode *temp = start;
    for(; temp->next != nullptr; temp = temp->next);
    return temp->value;
}

bool LinkedIntList::isEmpty() const
{
    return start == nullptr;
}



bool LinkedIntList::contains(const int value) const
{
    LinkNode *result = search(start, value);
    return result != nullptr;
}

void LinkedIntList::addFront(const int value)
{
    m_size++;

    LinkNode *newNode = new LinkNode(value);
    newNode->next = start;
    start = newNode;
}

void LinkedIntList::addBack(const int value)
{
    m_size++;
    LinkNode *tail = new LinkNode(value);

    if (start == nullptr)
    {
        start = tail;
    }
    else
    {
        LinkNode *temp = start;
        for(; temp->next != nullptr; temp = temp->next);
        temp->next = tail;
    }
}

void LinkedIntList::addAfter(int refValue, int value)
{
    m_size++;
    LinkNode* keyNode = search(start, refValue);
    if (keyNode != nullptr)
    {
        LinkNode* insert = new LinkNode(value);
        insert->next = keyNode->next;
        keyNode->next = insert;
    }
    else
    {
        addBack(value);
    }
}

void LinkedIntList::removeFront()
{
    m_size--;
    if(start != nullptr)
    {
        LinkNode *destroyNode = start;
        start = start->next;
        delete destroyNode;
    }
}

void LinkedIntList::removeBack()
{
    m_size--;
    LinkNode *temp = start;
    for(; temp->next->next != nullptr; temp = temp->next);
    delete temp->next;
    temp->next = nullptr;
}

void LinkedIntList::removeAfter(LinkNode* node)
{
    LinkNode *old = node->next;
    node->next = node->next->next;
    delete old;
}

void LinkedIntList::removeValue(int refValue)
{
    LinkNode* keyNode = start;
    if(keyNode->value == refValue)
    {
        removeFront();
        return;
    }
    while (keyNode->next != nullptr)
    {
        if(keyNode->next->value == refValue)
        {
            LinkNode* remove = keyNode->next;
            keyNode->next = keyNode->next->next;
            delete remove;
            m_size--;
            return;
        }
        keyNode = keyNode->next;
    }
}

bool LinkedIntList::removeValueMarty(int value) {

    // traverse the list to the end, if necessary
    LinkNode *curr = start;
    LinkNode *prev = nullptr;

    search(prev, curr, value);

    // case: the first node is the match
    if (prev == nullptr)
    {
        removeFront();
        return true;
    }
    // case: fail to find such value
    if (curr == nullptr)
    {
        
        return false;
    }
    // case: the node from the rest
    removeAfter(prev);
    return true;
}

void LinkedIntList::clear()
{
    release(start);
}

ostream& operator<<(ostream &os, const LinkedIntList &list)
{
    os << "Start: { -> ";
    if(!list.isEmpty())
    {
        for(LinkNode *temp = list.start; temp != nullptr; temp = temp->next)
        {
            os << temp->value << " -> ";
        }
    }
    os << "}" << endl;
    return os;
}

void LinkedIntList::release(LinkNode *&currNode)
{
    if(currNode != nullptr)
    {
        LinkNode *old = currNode;
        currNode = currNode->next;
        release(currNode);
    }
}

LinkNode* LinkedIntList::search(LinkNode *currNode, const int value) const
{
    if (currNode == nullptr)
    {
        return nullptr;
    }
    else if(currNode->value == value)
    {
        return currNode;
    }
    else
    {
        return search(currNode->next, value);
    }
}

void LinkedIntList::search(LinkNode *&prevNode, LinkNode *&currNode, const int value)
{
    if (currNode == nullptr)
    {
        return;
    }
    else if(currNode->value == value)
    {
        return;
    }
    else
    {
        prevNode = currNode;
        currNode = currNode->next;
        search(prevNode, currNode, value);
    }
}
