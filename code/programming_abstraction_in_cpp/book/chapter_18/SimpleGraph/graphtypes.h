#ifndef GRAPHTYPES_H
#define GRAPHTYPES_H

#include <string>
#include "map.h"
#include "set.h"

struct Node;
struct Arc;

struct SimpleGraph
{
    Set<Node *> nodes;
    Set<Arc *> arcs;
    Map<std::string, Node *> nodeMap;
};

struct Node
{
    std::string name;
    Set<Arc *> arcs;
};

struct Arc
{
    Node *start;
    Node *finish;
    double cost;
};



#endif // GRAPHTYPES_H
