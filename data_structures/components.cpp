#include "components.h"

// VERTEX //
Vertex::Vertex(int labelNum) {
    label = labelNum;
}

Vertex::Vertex(int labelNum, float lon, float lat) {
    label = labelNum;
    longitude = lon;
    latitude = lat;
}

Edge *Vertex::getPath() {
    return path;
}

void Vertex::setPath(Edge *from) {
    path = from;
}

void Vertex::setVisited(bool a) {
    visited = a;
}

void Vertex::addEdge(Edge *newEdge) {
    outEdges.push_back(newEdge);
}

bool Vertex::getVisited() {
    return visited;
}

void Vertex::reset() {
    setVisited(false);
}

int Vertex::getLabel() {
    return label;
}

list<Edge *> Vertex::getEdges() {
    return outEdges;
}

double toRad(double coord) {
    return (coord * M_PI) / 180;
}

double Vertex::distanceTo(Vertex other) {
    double rad_lat1 = toRad(latitude);
    double rad_lon1 = toRad(longitude);
    double rad_lat2 = toRad(other.latitude);
    double rad_lon2 = toRad(other.longitude);

    double lat_diff = rad_lat2 - rad_lat1;
    double lon_diff = rad_lon2 - rad_lon1;
    double aux = sin(lat_diff/2) * sin(lat_diff/2) + cos(rad_lat1) * cos(rad_lat2) * sin(lon_diff/2) * sin(lon_diff/2);
    double c = 2 * atan2(sqrt(aux), sqrt(1 - aux));
    return c * 6371000;
}


// EDGE //
Edge::Edge(Vertex* originVertex, Vertex* destinationVertex, float dist) {
    destination = destinationVertex;
    origin = originVertex;
    distance = dist;
}

bool Edge::operator<(Edge other) {
    return distance < other.distance;
}

void Edge::setReverse(Edge *other) {
    reverse = other;
}

Edge* Edge::getReverse() {
    return reverse;
}

Vertex* Edge::getOrigin() {
    return origin;
}

Vertex* Edge::getDestination() {
    return destination;
}

float Edge::getDistance() {
    return distance;
}
