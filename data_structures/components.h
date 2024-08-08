#ifndef COMP_H
#define COMP_H

#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <tgmath.h>
#include <math.h>
#include "MutablePriorityQueue.h"
using namespace std;

class Edge;
///This class is responsible for storing the components of each vertex
class Vertex {
public:
    ///Constructor with parameters
    ///
    ///O(1) complexity.
    Vertex(int labelNum);
    Vertex(int labelNum, float lon, float lat);

    ///Has the function of returning the path of a location
    ///
    ///O(1) complexity.
    Edge *getPath();
    ///Has the function of checking if a vertex has already been visited
    ///
    ///O(1) complexity.
    bool getVisited();
    ///Identification of a location
    ///
    /// O(1) complexity;
    int getLabel();

    ///Has the function of returning the list with all the edges
    ///
    ///O(1) complexity.
    list<Edge *> getEdges();

    ///Has the function of creating the locations path
    ///
    ///O(1) complexity.
    void setPath(Edge *from);

    ///Has the function of checking if a vertex has already been visited
    ///
    ///O(1) complexity.
    void setVisited(bool a);
    ///Has the function of adding an edge
    ///
    ///O(1) complexity.
    void addEdge(Edge *newEdge);

    double distanceTo(Vertex other);

    ///Has the function of reseting the attributes of the vertexes
    ///
    ///O(1) complexity.
    void reset();

protected:
    ///Integer with the identification of a location
    int label;
    ///initializes the vertex to not visited
    bool visited = false;
    ///initialize the path to null
    Edge *path = nullptr;
    ///list of the edges leaving the vertex
    list<Edge *> outEdges;
    float longitude, latitude;
};

///This class is responsible for storing the components of each edge
class Edge {
public:
    /// constructor with parameters
    ///
    ///O(1) complexity.
    Edge(Vertex* originVertex, Vertex* destinationVertex, float dist);
    ///operator overload
    bool operator<(Edge a);

    ///Has the function of  counterparting the edge
    ///
    ///O(1) complexity.
    void setReverse(Edge *other);

    /// Has the function of returning the reverse edge
    ///
    ///O(1) complexity.
    Edge* getReverse();
    ///Has the function of returning the origin edge of a vertex
    ///
    /// O(1) complexity.
    Vertex* getOrigin();
    ///Has the function of returning the destination edge of a vertex
    ///
    /// O(1) complexity.
    Vertex* getDestination();
    ///Has the function of returning the distance between two edges
    ///
    /// O(1) complexity.
    float getDistance();

    ///Has the function of calling the MutablePriorityQueue class
    ///
    ///O(n) complexity.
    friend class MutablePriorityQueue<Edge>;

protected:
    ///float that represents the distance between two edges
    float distance;
    ///the reverse edge
    Edge* reverse;
    ///the origin edge of the vertex
    Vertex* origin;
    ///the destination edge of the vertex
    Vertex* destination;
    ///a queue with indexes
    int queueIndex; // for mutable priority queue
};

#endif
