#include <stdexcept>
#include "LinkedIntList.h"

LinkedIntList::LinkedIntList()
              :m_size(0), start(nullptr)
{
}

LinkedIntList::~LinkedIntList()
{
    release(start);
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
    if(start != nullptr)
    {
        LinkNode *old = start;
        start = new LinkNode;
        start->value = value;
        start->next = old;
    }
    else
    {
        start = new LinkNode;
        start->next = nullptr;
        start->value = 0;
    }
}

void LinkedIntList::addBack(const int value)
{
    m_size++;
    LinkNode *tail = new LinkNode;
    tail->value = value;
    tail->next = nullptr;

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
    LinkNode* keyNode = search(start, refValue);
    if (keyNode != nullptr)
    {
        LinkNode* insert = new LinkNode;
        insert->value = value;
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
    if(start != nullptr)
    {
        LinkNode *destroyNode = start;
        start = start->next;
        delete destroyNode;
    }
}

void LinkedIntList::removeBack()
{
    LinkNode *temp = start;
    for(; temp->next->next != nullptr; temp = temp->next);
    delete temp->next;
    temp->next = nullptr;
}

void LinkedIntList::removeValue(int value)
{
    LinkNode* keyNode = search(start, value);
    if (keyNode != nullptr)
    {
        LinkNode* remove = keyNode;
        keyNode = keyNode->next;
        delete remove;
    }
}

void LinkedIntList::clear()
{
    release(start);
}

ostream& operator<<(ostream &os, const LinkedIntList &list)
{
    os << "Start -> ";
    for(LinkNode *temp = list.start; temp != nullptr; temp = temp->next)
    {
        os << temp->value << " ->";
    }
    os << endl;
    return os;
}

void LinkedIntList::release(LinkNode* startNode)
{
    if(startNode->next == nullptr)
    {
        delete startNode;
        return;
    }
    else
    {
        release(startNode->next);
        delete startNode;
    }
}

LinkNode* LinkedIntList::search(LinkNode *startNode, const int value) const
{
    if (startNode == nullptr)
    {
        return nullptr;
    }
    else if(startNode->value == value)
    {
        return startNode;
    }
    else
    {
        return search(startNode->next, value);
    }
}