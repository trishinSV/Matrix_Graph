//
//  List.hpp
//  Matrix_Graph
//
//  Created by Сергей Тришин on 10.05.17.
//  Copyright © 2017 Сергей Тришин. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
//#include <iterator> // заголовок итераторов

using namespace std;

class adjList {
    vector<list<int>> graph;
    size_t size;
    
    
public:
    adjList(){
        size = 0;
    }
    ~adjList(){
        graph.clear();

    }
    
    void buildGraph(istream& istream)
    {
        // initializes number of nodes
        istream >> size;
        string lineBreak;
        
        graph.resize(size);
        // reads extra white space
        getline(istream, lineBreak);
        
        int vertex1, vertex2, cost;
        while (true)
        {
            if (istream.eof())
            {
                break;
            }
            istream >> vertex1;
            istream >> vertex2;
            istream >> cost;
            if (vertex1 == 0 || vertex2 == 0 || cost == 0)
            {
                break;
            }
            insertEdge(vertex1, vertex2, cost);
        }
        
    }
    
    void insertEdge(int startIndex, int endIndex, int cost)
    {
        if (startIndex > 0 &&
            startIndex < 101 &&
            endIndex > 0 &&
            endIndex < 101 &&
            cost > 0)
        {
            graph[startIndex-1].push_back(endIndex);
        }
        
    }
    
    void print (){
         cout << endl;
        for (int i = 0; i < size; i++) {
            cout << i+1 << " ";
             copy(graph[i].begin(), graph[i].end(), ostream_iterator<int>(cout," "));
            cout << endl;
        }
        
    }
    
    
    
    
    void findVertex(int vertex){
        
        int i = 0;
        vertex=vertex-1;
        bool flag = false;
        while (i != size) {
            flag = false;
            std::list<int>::iterator findIter = std::find(graph[i].begin(), graph[i].end(), vertex);
            if (findIter == graph[i].end() || vertex == i) {
                for(std::list<int>::iterator iter = graph[i].begin(); iter != graph[i].end(); iter++)
                {
                   findIter = std::find(graph[*iter].begin(), graph[*iter].end(), vertex);
                    if (findIter != graph[*iter].end()) {
                        flag = true;
                        i++;
                        break;
                    }
                }
            }
            else {
                flag = true;
                i++;
            }
            if (flag == false) {
                cout << i+1 << " - вершина" << endl;
                i++;
                // break;
            }
    
        } 
    }
    
    void deleteVertex(int vertex) {
        
        
        graph.erase(graph.begin() + vertex-1);
        size--;
        for (int i = 0; i < size; i++) {
            std::list<int>::iterator findIter = std::find(graph[i].begin(), graph[i].end(), vertex);
            if (findIter != graph[i].end()) {
                graph[i].erase(findIter);
            }
        }  
    }
    
    
    
    
};









#endif /* List_hpp */
