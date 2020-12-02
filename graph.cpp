#include "graph.h"
using namespace std;


graphWeighted::graphWeighted(graph const &graph)        // Conversion constructor
{
	this->noOfVertices = graph.noOfVertices;			// Set the number of vertices
	this->noOfEdges = graph.noOfEdges;					// Set the number of edges

	for (int i = 0; i < noOfEdges; i++)					// Set the edges
	{
		(this->pEdge).push_back(edge(graph.pEdge[i].source, graph.pEdge[i].destination, graph.pEdge[i].weight));
	}
	for (int i = 0; i < noOfVertices; i++)               //	Set the vertices cost(weight)
	{
		this->verticeWeight.push_back(0);
	}
}

graph* loadGraph(ifstream& fp) 
{
	int V, E;
	fp >> V;
	fp >> E;

	graph* G = new graph();					            // Allocate memory for the graph
	G->noOfVertices = V;								// Set the number of vertixes
	G->noOfEdges = E;									// Set the number of edges

	int source = 0, destination = 0, weight = 0;
	for (int i = 0; i < E; i++)							// Set the edges
	{
		fp >> source>> destination >> weight;
		(G->pEdge).push_back(edge(source,destination,weight));
	}
	fp.close();
	return G;
}

void graphGenerator(char* fileName)
{
	int noOfEdges = 0;
	srand((unsigned int)time(0));

	FILE* fp = fopen(fileName, "w");
	int noOfVertices = 50;										// The number of vertices the graph will have
	for (int i = 0; i < noOfVertices; i++)						// For each vertex generate between 1 and 4 edges
	{
		int currEdges = rand() % 3 + 1;
		noOfEdges += currEdges;									// Add them to the total number of vertices
		edge* pEdge = new edge [ currEdges];				    // Alloc memory for vertex's edges
		for (int j = 0; j < currEdges; j++)						// For each edge
		{
			bool exists;
			do
			{
				pEdge[j].destination = rand() % noOfVertices;				// Give a destination vertex
				pEdge[j].source = i;										// Mark its source
				pEdge[j].weight = rand() % 30;								// Give a weight
				exists = false;
				for (int k = 0; k < j; k++)									// Check if the already exists or the vertex has an edge to himself
					if ((pEdge[j].destination == pEdge[k].destination) || (pEdge[j].destination == pEdge[j].source))
					{
						exists = true;
					}
				if (exists == false)										// If the edge doesn't exist,write the edge
				{
					fprintf(fp, "%d %d %d\n", pEdge[j].source, pEdge[j].destination, pEdge[j].weight);
				}
			} while (exists == true);
		}
		if (pEdge)
		{
			delete []pEdge;													// Dealloc pEdge memory
		}
	}
	fprintf(fp, "%d %d\n", noOfVertices, noOfEdges);						// Write the total number of vertices and edges
	fclose(fp);
}
