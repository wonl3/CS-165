#include "project3.h"
#include "node.h"

#ifndef GRAPH_H
#define GRAPH_H

class Graph : public AbstractGraph
{

private:

	int num_nodes, num_edges;
	std::map<int, Node> node_map;
	
public:

	Graph();

	int get_num_nodes();

	int get_num_edges();

	bool is_neighbor(Node u, Node v);
	
	void add_node(Node node);

	void add_edge(int node_id_1, int node_id_2);

	std::vector<Node> get_neighbors(Node u);

	std::map<int, Node> get_id_to_node_map();
	
	~Graph();
};

#endif
