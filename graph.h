#ifndef GRAPH_H
#define GRAPH_H

#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include <queue>
#include <new>
#include <string>

using namespace std;

typedef struct edge																	//structure for edge
{
	int source;																		//source vertex
	int destination;																//destination vertex
	int weight;																		//edge weight
	edge(int i=0, int j=0, int k=0): source(i), destination(j), weight(k)
	{}
} edge;

typedef struct graph
{
	int noOfVertices;																//number of vertices
	int noOfEdges;																	//number of edges
	vector<edge> pEdge;

}graph ;

typedef struct graphWeighted : graph
{
	vector<int>  verticeWeight;                                                    //vertices weight
	graphWeighted(graph const &);                                                  //conversion constructor

}graphWeighted;

graph* loadGraph(ifstream& fp);					                                   //creates the graph, V - number of vertices , E - number of Edges , returns the created graph

void graphGenerator(char* fileName);											   //function which generates directed graphs					

#endif