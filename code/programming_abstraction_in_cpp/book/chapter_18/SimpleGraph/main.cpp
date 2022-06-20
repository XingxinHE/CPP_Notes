#include "console.h"
#include "simpio.h"
#include "graphtypes.h"
#include "set.h"

using namespace std;

static const string ATLANTA = "Atlanta";
static const string BOSTON = "Boston";
static const string CHICAGO = "Chicago";
static const string DALLAS = "Dallas";
static const string DENVER = "Denver";
static const string LOS_ANGELES = "Los Angeles";
static const string NEW_YORK = "New York";
static const string PORTLAND = "Portland";
static const string SAN_FRANCISCO = "San Francisco";
static const string SEATTLE = "Seattle";

void addFlight(SimpleGraph &airline,
               const string &_start,
               const string &_finish,
               double _cost);
void addArcs(SimpleGraph &graph,
             Node *_start, Node *_finish,
             double _cost);
void addNode(SimpleGraph &graph, const string &name);

void initAirlineGraph(SimpleGraph &graph);
void printAdjacencyLists(SimpleGraph &graph);

int main()
{
    SimpleGraph airline;
    initAirlineGraph(airline);
    printAdjacencyLists(airline);

    return 0;
}

void printAdjacencyLists(SimpleGraph &graph)
{
    for(Node *node : graph.nodes)
    {
        cout << node->name << " -> ";
        bool first = true;
        for(Arc *arc : node->arcs)
        {
            if(!first) cout << ", ";
            cout << arc->finish->name;
            first = false;
        }
        cout << endl;
    }
}

void initAirlineGraph(SimpleGraph &airline)
{
    addNode(airline, ATLANTA);
    addNode(airline, BOSTON);
    addNode(airline, CHICAGO);
    addNode(airline, DALLAS);
    addNode(airline, DENVER);
    addNode(airline, LOS_ANGELES);
    addNode(airline, NEW_YORK);
    addNode(airline, PORTLAND);
    addNode(airline, SAN_FRANCISCO);
    addNode(airline, SEATTLE);

    addFlight(airline, ATLANTA, CHICAGO, 599);
    addFlight(airline, ATLANTA, DALLAS, 725);
    addFlight(airline, ATLANTA, NEW_YORK, 756);
    addFlight(airline, BOSTON, NEW_YORK, 191);
    addFlight(airline, BOSTON, SEATTLE, 2489);
    addFlight(airline, CHICAGO, DENVER, 907);
    addFlight(airline, DALLAS, DENVER, 650);
    addFlight(airline, DALLAS, LOS_ANGELES, 1240);
    addFlight(airline, DALLAS, SAN_FRANCISCO, 1468);
    addFlight(airline, DENVER, SAN_FRANCISCO, 954);
    addFlight(airline, PORTLAND, SAN_FRANCISCO, 550);
    addFlight(airline, PORTLAND, SEATTLE, 130);

}

void addNode(SimpleGraph &graph, const string &name)
{
    Node *neuw = new Node;
    neuw->name = name;
    graph.nodeMap[name] = neuw;
    graph.nodes.add(neuw);
}

void addArcs(SimpleGraph &graph,
             Node *_start, Node *_finish,
             double _cost)
{

    Arc *arc = new Arc;
    arc->start = _start;
    arc->finish = _finish;
    arc->cost = _cost;
    graph.arcs.add(arc);
    _start->arcs.add(arc);
}

void addFlight(SimpleGraph &airline,
               const string &_start,
               const string &_finish,
               double _cost)
{
    Node *_startNode = airline.nodeMap[_start];
    Node *_finishNode = airline.nodeMap[_finish];
    addArcs(airline, _startNode, _finishNode, _cost);
    addArcs(airline, _finishNode, _startNode, _cost);
}

