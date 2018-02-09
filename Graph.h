#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>


using namespace std;

struct Edge{
	int source;
	int destination;
	int weight;
	bool isMandatory;
};

struct CompEdges{
	bool operator()(const Edge* lhs, const Edge* rhs) const {
		return lhs->weight > rhs->weight;
	}
};

struct DisjointSets{
	vector<pair<int, pair<int, int>>> bundle;
	void addNode(int node);
	int find(int b);
	void merge(int x, int y);
	int getPapas();
};

class Graph
{

public:
	Graph();
	~Graph();
	int kruskalMST();
	void addEdge(int source, int destination, int weight, bool isMandatory);
	vector<int> get_vertices();
	int get_cost();
	bool get_cycle();
	int get_components();
	void List();
private:
	vector<Edge*> universal;
	vector<Edge*> v_solution;
	struct graph* the_graph;
	struct DisjointSets ds;
	priority_queue<Edge*, vector<Edge*>, CompEdges > pq;
	priority_queue<Edge*, vector<Edge*>, CompEdges > pq_mandatory;
	priority_queue<Edge*, vector<Edge*>, CompEdges > pq_solution;
	int cost;
	bool isCycle;
	int components;

};

#endif
