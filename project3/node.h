#include "project3.h"

#ifndef NODE_H
#define NODE_H

class Node
{

private:

	int id;

public:

	std::vector<int> neighbors;
	
	Node()
	{ id = 0; }

	Node(int node_id)
	{ id = node_id; }

	int get_node_id()
	{ return id; }

	int get_degree()
	{ return neighbors.size(); }

	bool operator== (const Node& other) const
	{ return id == other.id; }

	void add_neighbor(Node node)
	{
		neighbors.push_back(node.get_node_id());
	}

	bool find(Node node)
	{
		for (std::vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
			if ((*it) == node.get_node_id())
				return true;

		return false;
	}

	~Node()
	{

	}	
};

#endif
