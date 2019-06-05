#include "graph.h"

Graph::Graph()
{
	num_nodes = 0, num_edges = 0;
}


int Graph::get_num_nodes()
{ return num_nodes; }

int Graph::get_num_edges()
{ return num_edges; }

bool Graph::is_neighbor(Node u, Node v)
{
	if (node_map.find(u.get_node_id()) == node_map.end())
	{
		std::cout << "Node " << u.get_node_id() << " Not in graph.\n";
		exit(1);
	}

	if (node_map.find(v.get_node_id()) == node_map.end())
	{
		std::cout << "Node " << v.get_node_id() << " Not in graph.\n";
		exit(1);
	}

	return u.find(v) && v.find(u);
}

void Graph::add_node(Node node)
{
	if (node_map.find(node.get_node_id()) != node_map.end())
	{
		std::cout << "Trying to insert a node with a pre-existing node number.\n";
		exit(1);
	}

//	std::cout << "Inserting Node Num: " << node.get_node_id() << std::endl;
	node_map.insert(std::pair<int, Node>(node.get_node_id(), node));
	++num_nodes;
}

void Graph::add_edge(int node_id_1, int node_id_2)
{
	std::cout << "Creating an edge between Node " << node_id_1 << " and Node " << node_id_2 << std::endl;
//	if (node_id_1 == 0 || node_id_2 == 0) return;

	
	//check if edge exists
	if (Graph::is_neighbor(node_map[node_id_1], node_map[node_id_2]))
	{
		std::cout << "Edge already exists.\n";
		exit(1);
	}

	// Check if self-edge
	if (node_id_1 == node_id_2)
	{
		std::cout << "Trying to add a node as a neighbor of itself.\n";
		exit(1);
	}

	node_map[node_id_1].add_neighbor(node_map[node_id_2]);
	node_map[node_id_2].add_neighbor(node_map[node_id_1]);

	++num_edges;
}

std::vector<Node> Graph::get_neighbors(Node u)
{
	std::vector<Node> v(u.neighbors.size());
	for (int i = 0; i < u.neighbors.size(); ++i)
	{
		v[i] = node_map[u.neighbors[i]];
	}
	return v;
}

std::map<int, Node> Graph::get_id_to_node_map()
{ return node_map; }

Graph::~Graph()
{

}
