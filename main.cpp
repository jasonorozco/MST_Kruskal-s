#include <iostream>
#include <string>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include<sstream>
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[]){

	string data;
	Graph *graph = new Graph;

//test
/*
			test1->addEdge(5,1,1,true);
			test1->addEdge(1,2,3,false);
			test1->addEdge(5,2,4,false);
			test1->addEdge(3,5,6,false);
			test1->addEdge(4,5,7,false);
			test1->addEdge(2,3,5,false);
			test1->addEdge(3,4,2,false);
			test1->addEdge(7,6,9,false);
			test1->addEdge(6,8,10,false);
			test1->addEdge(7,8,11,false);
*/
/*
			test1->addEdge(1,2,5,false);
			test1->addEdge(3,4,7,false);
			test1->addEdge(4,5,6,false);
			test1->addEdge(5,6,4,false);
			test1->addEdge(2,8,8,false);
			test1->addEdge(12,9,10,false);
*/

	while(true){
		string line;
		getline(cin, line);
		stringstream ss(line);
		ss >> data;
		if(data=="BID"){
			int node_number1;
			int node_number2;
			int edge_cost;
			ss >> node_number1;
			ss >> node_number2;
			ss >> edge_cost;
			graph->addEdge(node_number1, node_number2, edge_cost, false);
		}
		else if(data=="MANDATORY"){
			int node_number1;
			int node_number2;
			int edge_cost;
			ss >> node_number1;
			ss >> node_number2;
			ss >> edge_cost;
			graph->addEdge(node_number1, node_number2, edge_cost, true);
		}
		else if(data=="COST?"){
			graph->kruskalMST();
			cout << graph->get_cost() << endl;
		}
		else if(data=="COMPONENTS?"){
			graph->kruskalMST();
			cout <<graph->get_components() << endl;
		}
		else if(data=="CYCLE?"){
			if(graph->get_cycle()==true)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if(data=="LIST?"){
			graph->kruskalMST();
			graph->List();
		}

		else if(data=="END"){
			exit(0);
		}

}





return 0;
}
