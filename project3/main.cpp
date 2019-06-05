#include "project3.h"
#include "erdos_renyi.cpp"

int main()
{
	Node node(3);

	Graph g = make_graph(4, std::vector<int>{1,2,3,4}, std::vector<int>{2,3,1,1});
	std::cout << "Number of nodes = " << g.get_num_nodes() << std::endl;		
	std::cout << "Number of edges = " << g.get_num_edges() << std::endl;
	std::map<int, Node> id_map = g.get_id_to_node_map();

	nl();
	int d = get_diameter(g);
	std::cout << "Diameter = " << d << std::endl;
	
	nl();
	std::cout << "Num of 2-edge paths = " << get_num_of_2_edge_paths(g) << std::endl;

	nl();
	int t = get_num_of_triangles(g);
	std::cout << "Triangle Count = " << t << std::endl;

	float c = get_clustering_coefficient(g);
	std::cout << "Cluttering Coefficient = " << c << std::endl;

	return 0;
}
