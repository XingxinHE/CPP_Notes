#include <iostream>
#include <string>
#include <stdexcept>
#include "hashmap.h"

using namespace std;

HashMap::HashMap()
       :m_nodeArray(nullptr), m_count(0),
        m_bucket(INITIAL_BUCKET), m_loadFactor(m_count / m_bucket)
{
    m_nodeArray = new Node*[m_bucket];
    for (int i = 0; i < m_bucket; i++)
    {
        m_nodeArray[i] = nullptr;
    }
}

HashMap::~HashMap()
{
    for (int i = 0; i < m_bucket; i++)
    {
        Node *node = m_nodeArray[i];
        while (node != nullptr)
        {
            Node *old = node;
            node = node->next;
            delete old;
        }
    }
}

int HashMap::size() const
{
    return m_count;
}

bool HashMap::isEmpty() const
{
    return m_count == 0;
}

string HashMap::get(const string &_key) const
{
    int hash = hashCode(_key);
    int bucket = getBucket(hash);
    Node *result = findNode(bucket, _key);
    return result==nullptr? "" : result->value;
}

void HashMap::put(const std::string &_key, const std::string &_value)
{
    (*this)[_key] = _value;
}

bool HashMap::containsKey(std::string _key) const
{
    int hash = hashCode(_key);
    int bucket = getBucket(hash);
    Node *bucketPtr = m_nodeArray[bucket];
    while(bucketPtr != nullptr)
    {
        if (bucketPtr->key == _key)
        {
            return true;
        }
        else
        {
            bucketPtr = bucketPtr->next;
        }
    }
    return false;
}


void HashMap::remove(std::string _key)
{
    int hash = hashCode(_key);
    int bucket = getBucket(hash);
    Node *curr = m_nodeArray[bucket];
    Node *prev = nullptr;
    while(curr != nullptr)
    {
        if (curr->key == _key)
        {
            prev = curr->next;
            delete curr;
            return;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return;
}

string HashMap::operator[](string _key) const
{
    if(!containsKey(_key))
    {
        throw std::invalid_argument("Key does not exist in the hash table.");
    }
    
    return get(_key);
}

string& HashMap::operator[](string _key)
{
    int hash = hashCode(_key);
    int bucket = getBucket(hash);
    Node *node = findNode(bucket, _key);
    if(node == nullptr)
    {
        node = new Node(_key, string());
        node->next = m_nodeArray[bucket];
        m_nodeArray[bucket] = node;
    }
    return node->value;
}