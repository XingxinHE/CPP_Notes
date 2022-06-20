#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "map.h"
#include "set.h"

using namespace std;

template <typename NodeType, typename ArcType>
class Graph
{
public:
    Graph();
    ~Graph();

    int size() const;
    bool isEmpty() const;
    void clear();

    NodeType *addNode(string name);
    NodeType *addNode(NodeType *node);

    void removeNode(string name);
    void removeNode(NodeType *node);

    NodeType *getNode(string name) const;

    ArcType *addArc(string sStart, string sEnd);
    ArcType *addArc(NodeType *startNode, NodeType *endNode);
    ArcType *addArc(ArcType *arc);

    void removeArc(string sStart, string sEnd);
    void removeArc(NodeType *startNode, NodeType *endNode);
    void removeArc(ArcType *arc);

    bool isConnected(string sStart, string sEnd) const;
    bool isConnected(NodeType *startNode, NodeType *endNode) const;

    Set<NodeType *> & getNodeSet();

    Set<ArcType *> & getArcSet();
    Set<ArcType *> & getArcSet(NodeType *node);
    Set<ArcType *> & getArcSet(string name);

    Set<NodeType *> getNeighbors(NodeType *node);
    Set<NodeType *> getNeighbors(string name);

    Graph(const Graph & src);
    const Graph & operator=(const Graph &src);



private:

    Set<NodeType *> nodes;
    Set<ArcType *> arcs;
    Map<string, NodeType *> nodeMap;

    void deepCopy(const Graph &src);
    NodeType *getExistingNode(string name) const;
};



template <typename NodeType, typename ArcType>
Graph<NodeType, ArcType>::Graph()
{
    /* Empty */
}

template <typename NodeType, typename ArcType>
Graph<NodeType, ArcType>::~Graph()
{
    clear();
}

template <typename NodeType, typename ArcType>
int Graph<NodeType, ArcType>::size() const
{
    return this->nodes.size();
}

template <typename NodeType, typename ArcType>
bool Graph<NodeType, ArcType>::isEmpty() const
{
    return nodes.isEmpty();
}

template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::clear()
{
    for(NodeType *node : nodes)
    {
        delete node;
    }
    for(ArcType *arc : arcs)
    {
        delete arc;
    }
    this->arcs.clear();
    this->nodes.clear();
    this->nodeMap.clear();
}

template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::addNode(string name)
{
    if(nodeMap.containsKey(name))
    {
        error("addNode: Node " + name + " already exists");
    }
    NodeType *node = new NodeType();
    node->name = name;
    return addNode(node);
}

template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::addNode(NodeType *node)
{
    nodes.add(node);
    nodeMap[node->name] = node;
    return node;
}

template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeNode(string name)
{
    removeNode(getExistingNode(name));
}

template <typename NodeType, typename ArcType>
void Graph<NodeType, ArcType>::removeNode(NodeType *node)
{
    Vector<ArcType *> toRemove;
    for(ArcType *arc : arcs)
    {
        if(arc->start == node || arc->finish == node)
        {
            toRemove.add(arc);
        }
    }
    for(ArcType *arc : toRemove)
    {
        removeArc(arc);
    }
    nodes.remove(node);
}

template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::getNode(string name) const
{
    return nodeMap.get(name);
}

template <typename NodeType, typename ArcType>
NodeType *Graph<NodeType, ArcType>::getExistingNode(string name) const
{
    NodeType *node = nodeMap.get(name);
    if(node == nullptr) error("No node named " + name);
    return node;
}

template <typename NodeType, typename ArcType>
ArcType *Graph<NodeType, ArcType>::addArc(string sStart, string sEnd)
{
    return addArc(getExistingNode(sStart), getExistingNode(sEnd));
}

template <typename NodeType, typename ArcType>
ArcType *Graph<NodeType, ArcType>::addArc(NodeType *startNode, NodeType *endNode)
{
    ArcType *arc = new ArcType();
    arc->start = startNode;
    arc->end = endNode;
    return addArc(arc);
}

template <typename NodeType, typename ArcType>
ArcType *Graph<NodeType, ArcType>::addArc(ArcType *arc)
{
    arc->start->arcs.add(arc);
    arcs.add(arc);
    return arc;
}


#endif // GRAPH_H
