#include "reader.h"

Reader::Reader() {}

Graph Reader::readDifferentToy(string name) {
    Graph graph = Graph(false);
    ifstream file;
    string line, from, to, a, dist;
    int fromID, toID, greater, maxy = -1;
    Vertex *fromVertex, *toVertex;

    file.open("data/toy/" + name + ".csv");

    getline(file, line);
    while (getline(file, line)) {
        stringstream thisLine(line);

        getline(thisLine, from, ',');
        getline(thisLine, to, ',');
        getline(thisLine, dist, ',');
        getline(thisLine, a, '\n');

        fromID = stoi(from);
        toID = stoi(to);
        greater = max(fromID, toID);

        if (graph.getVertex(greater) == nullptr) 
            graph.massCreateVertexes(maxy, greater);
        
        graph.addEdge(graph.getVertex(fromID), graph.getVertex(toID), stod(dist));
        maxy = max(maxy, greater);
    }

    file.close();
    return graph;
}

Graph Reader::readToy(string name) {
    if (name == "tourism") return readDifferentToy(name);
    Graph graph = Graph(false);
    ifstream file;
    string line, from, to, dist;
    int fromID, toID, greater, maxy = -1;
    Vertex *fromVertex, *toVertex;

    file.open("data/toy/" + name + ".csv");

    getline(file, line);
    while (getline(file, line)) {
        stringstream thisLine(line);

        getline(thisLine, from, ',');
        getline(thisLine, to, ',');
        getline(thisLine, dist, '\n');

        fromID = stoi(from);
        toID = stoi(to);
        greater = max(fromID, toID);

        if (graph.getVertex(greater) == nullptr) 
            graph.massCreateVertexes(maxy, greater);
        
        graph.addEdge(graph.getVertex(fromID), graph.getVertex(toID), stod(dist));
        maxy = max(maxy, greater);
    }

    file.close();
    return graph;
}

Graph Reader::readExtra(string name) {
    Graph graph = Graph(false);
    ifstream file;
    string line, from, to, dist;
    int fromID, toID, greater, maxy = -1;
    Vertex *fromVertex, *toVertex;

    file.open("data/extra/" + name + ".csv");

    while (getline(file, line)) {
        stringstream thisLine(line);

        getline(thisLine, from, ',');
        getline(thisLine, to, ',');
        getline(thisLine, dist, '\n');

        fromID = stoi(from);
        toID = stoi(to);
        greater = max(fromID, toID);

        if (graph.getVertex(greater) == nullptr) 
            graph.massCreateVertexes(maxy, greater);
        
        graph.addEdge(graph.getVertex(fromID), graph.getVertex(toID), stod(dist));
        maxy = max(maxy, greater);
    }

    file.close();
    return graph;
}

Graph Reader::readReal(string name){
    Graph graph = Graph(true);
    ifstream file;
    string line, id, longitude, latitude;
    string from, to, dist;
    Vertex *fromVertex, *toVertex;
    int fromID, toID;

    file.open("data/real_world/" + name + "/nodes.csv");

    // READ NODES 
    getline(file, line);
    while (getline(file, line)) {
        stringstream thisLine(line);

        getline(thisLine, id, ',');
        getline(thisLine, longitude, ',');
        getline(thisLine, latitude, '\n');

        Vertex *child = new Vertex(stoi(id), stod(longitude), stod(latitude));
        graph.addVertex(child);
    }
    file.close();

    // READ EDGES 
    file.open("data/real_world/" + name + "/edges.csv");
    getline(file, line);
    while (getline(file, line)) {
        stringstream thisLine(line);

        getline(thisLine, from, ',');
        getline(thisLine, to, ',');
        getline(thisLine, dist, '\n');

        graph.addEdge(graph.getVertex(stoi(from)), graph.getVertex(stoi(to)), stod(dist));
    }
    file.close();

    graph.distributeEdges();
    return graph;
}