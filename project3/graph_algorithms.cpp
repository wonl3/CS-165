#include "project3.h"
#include "graph.cpp"

Graph make_graph(int num_nodes, std::vector<int> u, std::vector<int> v)
{
	Graph graph;
	for (int i = 1; i <= num_nodes; ++i)
	{
		Node n(i);
		graph.add_node(n);
	}

	for (int i = 0; i < u.size(); ++i)
	{
		graph.add_edge(u[i], v[i]);
	}

	return graph;
}

std::vector<Node> get_degeneracy_ordering(Graph graph)
{
	std::vector<Node> L;
	
}

int get_diameter(Graph graph)
{
	
}

float get_clustering_coefficient(Graph graph)
{
	
}

std::map<int, int> get_degree_distribution(Graph graph)
{
	std::map<int, int> deg_dis;

	for (std::map<int, Node>::iterator it = graph.get_id_to_node_map().begin(); it != graph.get_id_to_node_map().end(); ++it)
	{
		++deg_dis[(it->second).get_degree()];
	}
}
