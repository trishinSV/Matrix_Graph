
#include "GraphM.h"
#include <fstream>


GraphM::GraphM()
{
	// call to helper functions
	initializeTableType();
	initializeAdjacencyMatrixCost();
	size = 0;
}

GraphM::~GraphM(){}

void GraphM::initializeTableType()
{
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			T[i][j].dist = INFINITE;
			T[i][j].visited = false;
			T[i][j].path = 0;
		}
	}
}

void GraphM::setAllNotVisted()
{
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			T[i][j].visited = false;
		}
	}
}

void GraphM::initializeAdjacencyMatrixCost()
{
	for (int i = 0; i < MAXNODES; i++)
	{
		for (int j = 0; j < MAXNODES; j++)
		{
			C[i][j] = INFINITE;
		}
	}
}

void GraphM::buildGraph(istream& istream)
{
	// initializes number of nodes
	istream >> size; 
	string lineBreak;

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

void GraphM::findShortestPath()
{
	int V = 0;
	int W = 0;

	for (int i = 1; i <= size; i++)
	{
		// distance of sourse initialized to 0
		T[i][i].dist = 0; 

		for (int j = 1; j <= size; j++)
		{
				V = NotVistedMin(i);
				T[i][V].visited = true;

				for (int k = 1; k <= size; k++)
				{
					
					W = k;
					// if adjacent and not visited
					if (C[V][W] != INFINITE && !(T[i][W].visited))
					{
						// update adjacent to current 
						if(T[i][W].dist > (T[i][V].dist + C[V][W]))
						{
							T[i][W].dist = T[i][V].dist + C[V][W];
							T[i][W].path = V;
						}

					}
					
				}

		}

		// set all to not visited 
		// then re-iterate with next vertex
		setAllNotVisted(); 
	}

}


int GraphM::NotVistedMin(int row)
{
	int min = 1;
	int max = INFINITE;
	for (int i = 1; i <= size; i++)
	{
		// if the distance is less then max
		// and if not visited
		if (T[row][i].dist < max &&  !(T[row][i].visited))
		{
			// update min and max
			min = i;
			max = T[row][i].dist;
		}
	}

	//returns the min index. 
	return min;
}

void GraphM::insertEdge(int startIndex, int endIndex, int cost)
{
	if (startIndex > 0 && startIndex < 101
		&& endIndex > 0 && endIndex < 101
		&& cost > 0)
	{
		C[startIndex][endIndex] = cost;
	}
	
}

void GraphM::removeEdge(int startIndex, int endIndex)
{
	if (startIndex > 0 && startIndex < 101
		&& endIndex > 0 && endIndex < 101)
	{
		C[startIndex][endIndex] = INFINITE;
	}
	
	
}

void GraphM::displayAll() const
{

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (T[i][j].dist < INFINITE && T[i][j].dist > 0) {
                cout << T[i][j].dist << " ";
            }
            else
                cout << 0 << " ";
            
        }
        cout << endl;
    }
    cout << endl;

    
}

void GraphM::display(int vertex)
{
	
    for (int i = 1; i < size; i++) {
        if (T[vertex][i].dist > 0 && i != vertex) {
            deleteVertex(i);
        }
        
    }
    
    
    
    
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (C[i][j] < INFINITE) {
                cout << C[i][j] << " ";
            } else
            cout << 0 << " ";
        }
        cout << endl;
    }

    
}




void GraphM:: deleteVertex(int vertex){
    
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
           C[i][vertex] = 0;
        }
    
    }
}

void GraphM::getPath(int fromPath, int toPath) const
{
	if (fromPath != toPath && T[fromPath][toPath].dist < INFINITE)
	{
		getPath(fromPath, T[fromPath][toPath].path);
	}
		cout << " " << toPath;
	
}
