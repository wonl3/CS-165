#include "project3.h"
#include "graph_algorithms.cpp"

int main()
{
	Node node(3);

	Graph g = make_graph(3, std::vector<int>{2}, std::vector<int>{2});
	std::cout << g.get_num_nodes() << std::endl;		
	std::cout << g.get_num_edges() << std::endl;
	
	return 0;
}
