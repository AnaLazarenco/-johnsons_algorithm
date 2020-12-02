#include "bellman_ford.h"
using namespace std;

void BellmanFord1(struct graph* graph,vector<int>& dist, int src)
{
	int V = graph->noOfVertices;
	int E = graph->noOfEdges;

	// Step 1: Initialize distances from src to all other vertices 
	// as INFINITE 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// Step 2: Relax all edges |V| - 1 times. A simple shortest 
	// path from src to any other vertex can have at-most |V| - 1   edges 
	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->pEdge[j].source;
			int v = graph->pEdge[j].destination;
			int weight = graph->pEdge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	// Step 3: check for negative-weight cycles.  The above step 
	// guarantees shortest distances if graph doesn't contain 
	// negative weight cycle.  If we get a shorter path, then there 
	// is a cycle. 
	for (int i = 0; i < E; i++) {
		int u = graph->pEdge[i].source;
		int v = graph->pEdge[i].destination;
		int weight = graph->pEdge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return; // If negative cycle is detected, simply return 
		}
	}
	return ;

}
