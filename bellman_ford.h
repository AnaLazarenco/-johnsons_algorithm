#ifndef BELLMANFORD_H
#define BELLMANFORD_H
#define infinite INT_MAX
#define minfinite INT_MIN
#include "graph.h"

using namespace std;

/// <summary>
/// Bellman Ford algorithm
/// </summary>
/// <param name="graph"> Graph on which bellman ford is performed,source - the source vertex</param>
/// <param name="cost"> Vector of int, in which we hold the minimum distance between the source and all other vertices</param>
/// <param name="src"></param>
void BellmanFord1(graph* graph, vector<int>& cost, int src);		
																				
#endif


