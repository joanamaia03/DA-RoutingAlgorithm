#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include "graph.h"
#include "MutablePriorityQueue.h"

using namespace std;

Graph::Graph(bool reality) {
    isReal = reality;
}

Vertex* Graph::getVertex(int label) {
    if (vertexes.size() <= label) return nullptr;
    return vertexes[label];
}

Edge* Graph::getEdge(int sourceIndex, int destinationIndex) const{
    if(sourceIndex<0 || sourceIndex>=vertexes.size() || destinationIndex<0 || destinationIndex>=vertexes.size()){
        return nullptr;
    }
    for(Edge* edge:vertexes[sourceIndex]->getEdges()){
        if(edge->getDestination()->getLabel()==destinationIndex){
            return edge;
        }
    }
    return nullptr;
}

void Graph::massCreateVertexes(int firstlabel, int lastlabel) {
    for (int i = firstlabel + 1; i <= lastlabel; i++) {
        Vertex *hello = new Vertex(i);
        vertexes.push_back(hello);
    }
}

void Graph::addEdge(Vertex* a, Vertex* b, double dist) {
    Edge *direct = new Edge(a, b, dist);
    Edge *reverse = new Edge(b, a, dist);
    direct->setReverse(reverse);
    reverse->setReverse(direct);
    a->addEdge(direct);
    b->addEdge(reverse);
}

void Graph::addVertex(Vertex* toAdd) {
    vertexes.push_back(toAdd);
}

void Graph::reset() {
    for (Vertex* v: vertexes) {
        v->setVisited(false);
    }
}

void Graph::distributeEdges() {
    if (!isReal) return;
    vector<vector<double>> mat = getDistanceMatrix();
    for (int i = 0; i < vertexes.size(); i++) {
        for (int j = i + 1; j < vertexes.size(); j++) {
            if (mat[i][j] != -1) continue;
            addEdge(vertexes[i], vertexes[j], vertexes[i]->distanceTo(*vertexes[j]));
        }
    }
}

vector<vector<double>> Graph::getDistanceMatrix() {
    vector<vector<double>> result;
    for (int i = 0; i < vertexes.size(); i++) {
        result.push_back({});
        for (int j = 0; j < vertexes.size(); j++) {
            result[i].push_back(-1);
        }
    }
    
    int source, dest;
    for (Vertex *vertex : vertexes) {
        for (Edge *edge : vertex->getEdges()) {
            source = edge->getOrigin()->getLabel();
            dest = edge->getDestination()->getLabel();
            result[source][dest] = edge->getDistance();
            result[dest][source] = edge->getDistance();
        }
    }

    return result;
}

void Graph::prim() {
    Edge *currentEdge;
    MutablePriorityQueue<Edge> edgeQueue;
    Vertex *currentVertex = *vertexes.begin();
    currentVertex->setVisited(true);
    for (Edge *edgy : currentVertex->getEdges()) 
        edgeQueue.insert(edgy);

    while (!edgeQueue.empty()) {
        currentEdge = edgeQueue.extractMin();
        currentVertex = currentEdge->getDestination();
        if (currentVertex->getVisited()) continue;

        currentVertex->setVisited(true);
        currentVertex->setPath(currentEdge);
        for (Edge *edgy : currentVertex->getEdges()) 
            if (!edgy->getDestination()->getVisited())
                edgeQueue.insert(edgy);
    }   
}

double Graph::dfs(int id,  vector<int> *passedBy) {
    passedBy->push_back(vertexes[id]->getLabel());
    float cost = 0;
    for (auto it : vertexes[id]->getEdges()) {
        if (it->getDestination()->getPath() != it) continue; // CHECKS IF PATH WAS USED FOR MST!
        cost += it->getDistance() * 2;
        cost += dfs(it->getDestination()->getLabel(), passedBy);
    }

    return cost;
}

double Graph::triangleAproximationHeuristic() {
    cout << "Graph Read!\n";
    prim();
    cout << "Prim Finished!\n";
    vector<int> path;
    double result = dfs(0, &path);
    cout << "DFS Finished!\n";
    if (!isReal) return result;

    result = 0;
    vector<vector<double>> matrix = getDistanceMatrix();
    cout << "Matrix Fetched\n";
    for (int it = 0; it < path.size() - 1; it++) {
        result += matrix[path[it]][path[it + 1]];
    }
    cout << "Result Calculated!\n";

    return result;
}

int Graph::getVertexQuant() {
    return vertexes.size();
}

void Graph::backtrackTSP(vector<bool> &visited, double current, int numVisited, double cost, double& bestCost, queue<int> &shortestPath){
    visited[current]=true;
    shortestPath.push(current);
    if(numVisited==getVertexQuant() && getEdge(current, 0)){
        double newCost = cost + getEdge(current, 0)->getDistance();
        if (newCost < bestCost) {
            bestCost = newCost;
            queue<int> auxPath = shortestPath;
            shortestPath=auxPath;
        }
        return;
    }

    for(Edge* edge: vertexes[current]->getEdges()){
        Vertex* neighbour=edge->getDestination();
        int neighbourIndex = neighbour->getLabel();
        if(!visited[neighbourIndex] && getEdge(current, neighbourIndex)){
            visited[neighbourIndex]=true;
            backtrackTSP(visited, neighbourIndex, numVisited+1, cost+getEdge(current,neighbourIndex)->getDistance(), bestCost, shortestPath);
            visited[neighbourIndex]=false;
        }
    }
    visited[current]=false;
    shortestPath.pop();
}

vector<int> Graph::nearestNeighborTSP(Vertex* startPoint){
    Vertex* current = startPoint;
    Vertex* next;
    float minDist = INT_MAX;
    float totalDist = 0;
    vector<int> sequence;
    startPoint->setVisited(true);
    sequence.push_back(startPoint->getLabel());
    for(int j = 0; j < vertexes.size()-1; j++){
        for(Edge* edge : current->getEdges()){
            if(edge->getDestination()->getVisited()) continue;
            else if(minDist > edge->getDistance()){
                minDist = edge->getDistance();
                next = edge->getDestination();
                
            }
        }
        totalDist += minDist;
        current = next;
        sequence.push_back(current->getLabel());
    }

    for(Edge* edge : current->getEdges()){
        if (edge->getDestination()->getLabel() == startPoint->getLabel()){
            totalDist += edge->getDistance();
        }
    }
    sequence.push_back(totalDist);
    return sequence;
}
