#ifndef READER_H
#define READER_H

#include "components.h"
#include "Graph.h"

///This class is responsible for reading the files and create a graph based on them
class Reader {
    public:
    ///default constructor
    ///
    ///O(1) complexity.
    Reader();
    ///Has the function of reading the toy graphs file
    ///
    ///
    Graph readToy(string name);
    ///Has the function of reading a specific toy from the toy file
    ///
    ///
    Graph readDifferentToy(string name);
    ///Has the function of reading the extra fully-connected medium-size graph data sets file
    ///
    ///
    Graph readExtra(string name);
    ///Has the function of reading the real-world graphs data set file
    ///
    ///
    Graph readReal(string name);
};

#endif
