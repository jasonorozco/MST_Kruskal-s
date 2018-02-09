#include "Graph.h"
//hello Jason Orozco 9526880 jasonorozco@Umail.ucsb.edu
using namespace std;

	void DisjointSets::addNode(int node){
		for(unsigned int i=0; i < bundle.size(); i++){
			if(bundle[i].first == node){
				return;
			}
		}
		bundle.push_back(make_pair(node, make_pair(node, 0) ) );
}

	int DisjointSets::find(int b){
		int index;
		for(unsigned int i=0; i < bundle.size(); i++){
			if (b == bundle[i].first){
				index = i;
			}
		}

		if (b != bundle[index].second.first){
			bundle[index].second.first = find(bundle[index].second.first);
		}
		return bundle[index].second.first;
	}

	void DisjointSets::merge(int x, int y){
		int index;
		int index2;
		for(unsigned int i=0; i < bundle.size(); i++){
			if (x == bundle[i].first){
				index = i;
			}
		}
		for(unsigned int j=0; j < bundle.size(); j++){
			if (y == bundle[j].first){
				index2 = j;
			}
		}
		bundle[index].second.first = find(bundle[index].second.first);
		bundle[index2].second.first = find(bundle[index2].second.first);
		if(bundle[index].second.second > bundle[index2].second.second){
			bundle[index2].second.first = x;
		}
		else{
			bundle[index].second.first = y;

		}
		if(bundle[index].second.second == bundle[index2].second.second){
			bundle[index2].second.second++;
		}

	}

	int DisjointSets::getPapas(){
		vector<int> papas;
		int candidate;
		for(unsigned int i = 0; i < bundle.size(); i++){
			candidate = find(bundle[i].second.first);
			if( std::find(papas.begin(), papas.end(), candidate) == papas.end() && candidate!= 0)
				papas.push_back(candidate);
		}
		return papas.size();
	}
















Graph::Graph(){
	cost = 0;
}

void Graph::addEdge(int source, int destination, int weight, bool isMandatory){
	struct Edge* the_edge = new Edge;
	the_edge->source = source;
	the_edge->destination = destination;
	the_edge->weight = weight;
	the_edge->isMandatory = isMandatory;
	if(the_edge->isMandatory == false)
		pq.push(the_edge);
	else
		pq_mandatory.push(the_edge);
	universal.push_back(the_edge);
	ds.addNode(the_edge->source);
	ds.addNode(the_edge->destination);


}

/**
vector<int> Graph::get_vertices(){
	vector<int> nodes;
	int candidate;
	int candidate2;
	for(unsigned int i = 0; i < universal.size(); i++){
		candidate = universal[i]->source;
		candidate2 = universal[i]->destination;

		if( std::find(nodes.begin(), nodes.end(), candidate) == nodes.end() ) {
			nodes.push_back(candidate);
			the_graph->n_vertices++;
		}
		if( std::find(nodes.begin(), nodes.end(), candidate2) == nodes.end() ) {
			nodes.push(candidate2);
			the_graph->n_vertices++;
		}
	}
	return nodes;
}
**/

void Graph::List(){
	for(unsigned int i=0; i < v_solution.size(); i++){
		pq_solution.push(v_solution[i]);
}
	while(pq_solution.empty()==false){
		int source = pq_solution.top()->source;
		int destination = pq_solution.top()->destination;
		if (source < destination){
			cout << "(" << source << "," << destination << ") ";
		}
		else{
			cout << "(" << destination << "," << source << ") ";
		}
		pq_solution.pop();
	}
	cout << endl;
}

int Graph::kruskalMST(){
	Edge* solution;
	int source;
	int destination;
	int weight;
	int set_source, set_destination;
	bool m;

	while(pq_mandatory.empty()==false){
		solution = pq_mandatory.top();
		source = pq_mandatory.top()->source;
		destination = pq_mandatory.top()->destination;
		weight = pq_mandatory.top()->weight;
		m = pq_mandatory.top()->isMandatory;
		pq_mandatory.pop();
		set_source = ds.find(source);
		set_destination = ds.find(destination);

			if((set_source != set_destination) || ((set_source == set_destination) && m==true) || ){
				if((set_source == set_destination) && m==true){
					isCycle=true;
				}
				v_solution.push_back(solution);
				cost += weight;
				ds.merge(set_source, set_destination);
			}

	}

	while(pq.empty()==false){
		solution = pq.top();
		source = pq.top()->source;
		destination = pq.top()->destination;
		weight = pq.top()->weight;
		m = pq.top()->isMandatory;
		pq.pop();
		set_source = ds.find(source);
		set_destination = ds.find(destination);

			if((set_source != set_destination) || ((set_source == set_destination) && m==true)){
				if((set_source == set_destination) && m==true){
					isCycle=true;
				}
				v_solution.push_back(solution);
				cost += weight;
				ds.merge(set_source, set_destination);
			}

	}
	this->components = ds.getPapas();
	return cost;
}


int Graph::get_cost(){
	return this->cost;
}

bool Graph::get_cycle(){
	return isCycle;
}

int Graph::get_components(){
	return this->components;
}
