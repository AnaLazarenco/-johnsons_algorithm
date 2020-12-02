#include "Johnson.h"

void virtualNode(graph* G)
{
	for (int i = G->noOfEdges; i < G->noOfEdges + G->noOfVertices; i++)
	{
		G->pEdge.push_back(edge(G->noOfVertices, i - G->noOfEdges, 0));
	}
	
	G->noOfEdges = G->noOfEdges + G->noOfVertices;
	(G->noOfVertices)++;
}

void deleteVirtualNode(graph* G)
{
	(G->noOfVertices)--;
	G->noOfEdges = G->noOfEdges - G->noOfVertices;
	G->pEdge.erase(G->pEdge.begin() + G->noOfEdges, G->pEdge.end());

}

void Johnson(graph* G, ofstream& fp)
{
	graphWeighted* G1 = new  graphWeighted(*G);
	
	//Step1
	virtualNode(G);

	int source = G->noOfVertices - 1;      // Source for Bellman Ford
	vector<int> weigh(G->noOfVertices, 0); // Vector for min cost 

	//Step2
	BellmanFord1(G, weigh, source);

	//Step3
	deleteVirtualNode(G);

	vector<vector <int>> cost(G->noOfVertices, vector<int>(G->noOfVertices, inf)); // 2D array for min cost APSP
	vector<vector <int>> destination(G->noOfVertices, vector<int>(G->noOfVertices, inf)); //2D array for reconstruct path
	weigh.erase(weigh.end() - 1); // Delete cost for vitual node

	//Step4
	for (int i = 0; i < G1->noOfVertices; i++)
	{
		G1->verticeWeight[i] = weigh[i];
	}

	//Step5
	for (int i = 0; i < G->noOfEdges; i++)
	{
		G->pEdge[i].weight += weigh[G->pEdge[i].source] - weigh[G->pEdge[i].destination];
	}

	//Step6
	for (source = 0; source < G->noOfVertices; source++)
	{
		Dijkstra(source, G, cost, destination);

	}

	//Step7
	cout << "Array for APSP\n";
	for (source = 0; source < G->noOfVertices; source++)
	{
		for (int i = 0; i < G->noOfVertices; i++) {

			if (cost[source][i] != inf )
			{
				cost[source][i] += -weigh[source] + weigh[i];
				//or cost[source][i] += -G1->verticeWeight[source] + G1->verticeWeight[i]

				cout << cost[source][i] << " ";  //print Array
				if (cost[source][i] >= 0)
				{
					cout << " ";
				}
			}
			else {
				cout << '~' << "  ";
			}
			fp << cost[source][i] << " ";
		}
		fp << endl;
		cout << "\n";
	}
	cout << "\nAll path APSP\n";
	for (int i = 0; i < G->noOfVertices; i++)
	{
		cout << "\nSource :" << i << "\n";
		vector<bool> visit(G->noOfVertices, true);         // Vector of visited vertices  for reconstruct path
		reconstructPath(i, i, G1, destination, visit, "");
		visit.clear();
	}

	weigh.clear();
	destination.clear();
	cost.clear();
	delete G1;
	return ;
}

void driverProgram(char* inputFile, char* outputFile)
{
	ofstream fout;
	fout.open(outputFile);

	ifstream fin;
	fin.open(inputFile);
	graph* G = loadGraph(fin);
	
	Johnson(G,fout);

	fin.close();
	fout.close();
}

void reconstructPath(int src, int source, graphWeighted* G, vector<vector<int>> destination, vector<bool>& visited, string s)
{
	bool ok = true;
	s += to_string(source);
	for (int i = 0; i < G->noOfVertices; i++)
	{
		if (destination[src][i] == source && visited[i])
		{
			visited[i] = false;
			ok = false;
			reconstructPath(src, i, G, destination, visited, s+"->");
			continue;
		}
	}
	if (ok)
	{
		cout << s << endl;
	}
}
