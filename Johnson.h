#ifndef JOHNSON_H
#define JOHNSON_H
#include "Dijkstra.h"
#include "bellman_ford.h"

using namespace std;

void driverProgram(char* inputFile, char* outputFile);	

/// <summary>
///  Insert new node(vertice) and n edges which link virtual node with all nodes
///  virtual vertice is the last vertice 
///  virtual edges are the edges from E to E+V
/// </summary>
/// <param name="G"> Directed and weighted graph</param>
void virtualNode(graph* G);                                       

/// <summary>
/// Delete virtual node(vertice), and all virtual edges
/// </summary>
/// <param name="G"> Directed and weighted graph </param>
void deleteVirtualNode(graph* G); 

/// <summary>
/// Step1: Add new virtual vertice and edges 
///<para> Step2: Call Bellman_Ford with source vitual  vertice </para>
/// Step3: Delete virtual node, edges 
/// <para>Step4: Createa new graph which has cost for every vertices equal with min cost from Bellman Ford </para>
/// Step5: Recalculate weight cost
/// <para>Step6: Call  Dijkstra algorithm of V times  for every vertices </para>
/// Step7: Recalculate weight cost
/// </summary>
/// <param name="G"> Directed and weighted graph </param>
/// <returns></returns>
void Johnson(graph* G, ofstream& fp);

// Function that reconstructs all path from the source to all vertices
void reconstructPath(int src,int source, graphWeighted* G, vector<vector<int>> destination, vector<bool>&, string s);	

#endif //!JOHNSON_H


