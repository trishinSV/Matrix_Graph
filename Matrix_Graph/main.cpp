//
//  main.cpp
//  Matrix_Graph
//
//  Created by Сергей Тришин on 10.05.17.
//  Copyright © 2017 Сергей Тришин. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "GraphM.h"
#include "List.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    // part 1
    ifstream infile1("/Users/Sergey/Documents/Developer/Matrix_Graph/Matrix_Graph/data31.txt");
    if (!infile1) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    //for each graph, find the shortest path from every node to all other nodes
//    for (;;){
//        GraphM G;
//        G.buildGraph(infile1);
//        if (infile1.eof())
//            break;
//        G.findShortestPath();
//           G.displayAll();              // display shortest distance, path to cout
//        G.display(3);              // display path from node 3 to 1 to cout
//    }

    for (;;) {
        adjList L;
        L.buildGraph(infile1);
        if (infile1.eof())
            break;
         L.print();
        // L.findVertex(4);
        L.deleteVertex(2);
        L.print();
    }
    return 0;
}
