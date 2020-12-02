#include "graph.h"
#include "Dijkstra.h"

bool hasNegativeweights(struct graph* G)     //Check if graph has negative weight
{
	for (int i = 0; i < G->noOfEdges; i++) { // Check every edge
		if (G->pEdge[i].weight < 0)
			return  true;
	}
	return false;
}

void  Dijkstra(int src, struct graph* grap, vector<vector<int>>& dist, vector<vector<int>>& destination)
{
	// Create a priority queue to store vertices 
	// time to get minim node is log n
	priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

	//check if graph has negative weight
	if (hasNegativeweights(grap))
	{
		cout << "Has negative weights\n";
		return;
	}
	// Insert source itself in priority queue and initialize 
	// its distance as 0. 
	pq.push(make_pair(0, src));
	dist[src][src] = 0;

	/* Looping till priority queue becomes empty (or all
	  distances are not finalized) */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum distance  vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it  has to be done this way to keep the vertices 
		// sorted distance (distance must be first item  in pair) 
		int u = pq.top().second;
		pq.pop();

		// 'x' is used to get all adjacent vertices of a vertex 
		for (auto x : grap->pEdge)
		{
			// Get vertex label and weight of current adjacent 
			// of u. 
			int v = x.destination;
			int weight = x.weight;

			// If there is shorted path to v through u. 
			if (x.source == u)
			{
				if (dist[src][v] > dist[src][u] + weight)
				{
					// Updating distance of v 
					dist[src][v] = dist[src][u] + weight;
					pq.push(make_pair(dist[src][v], v));
					// 2D vector for reconstruct path
					destination[src][v] = x.source;
				}
			}
		}
	}
}
