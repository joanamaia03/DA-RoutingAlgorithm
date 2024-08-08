#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <queue>
#include "components.h"

///This class is responsible for building the graph by creating Edges and Vertexes
class Graph {
public:
    ///default constructor
    ///
    ///O(1) complexity.
    Graph(bool reality);

    ///Has the function of returning a vertex
    ///
    ///O(n) complexity.
    Vertex* getVertex(int label);

    void distributeEdges();

    void massCreateVertexes(int firstlabel, int lastLabel);
    ///Has the function of adding an edge
    ///
    /// O(1) complexity.
    void addEdge(Vertex* a, Vertex* b, double dist);
    ///Has the function of reseting the vertexes
    ///
    ///O(n) complexity.
    void reset();

    void prim();
    void backtrackTSP(vector<bool> &visited, double current, int numVisited, double cost, double& bestCost, queue<int> &shortestPath);

    double dfs(int id, vector<int> *passedBy);
    ///Has the function of returning the number of vertexes in a graph
    ///
    /// O(1) complexity.
    int getVertexQuant();

    double triangleAproximationHeuristic();
    void addVertex(Vertex *toAdd);
    Edge* getEdge(int sourceIndex, int destinationIndex) const;
    vector<int> nearestNeighborTSP(Vertex* startPoint);
    vector<vector<double>> getDistanceMatrix();

private:
    ///vector with all the vertexes
    vector<Vertex *> vertexes;
    bool isReal;
};
#endif
