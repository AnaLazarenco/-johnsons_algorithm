#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__
#define inf 999999

#include "graph.h"

// Check if graph has negative weight
bool hasNegativeweights(struct graph* graph);     

// With priority queue , time: O(E logV)
void Dijkstra(int src, struct graph* grap, vector<vector<int>>& dist, vector<vector<int>>& destination);  

#endif