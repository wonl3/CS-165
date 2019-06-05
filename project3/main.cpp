#include "project3.h"
#include "erdos_renyi.cpp"

int main()
{
	Node node(3);

	Graph g = make_graph(3, std::vector<int>{1,2,3}, std::vector<int>{2,3,1});
	std::cout << g.get_num_nodes() << std::endl;		
	std::cout << g.get_num_edges() << std::endl;

	nl();
	std::map<int, Node> id_map = g.get_id_to_node_map();
	std::cout << g.is_neighbor(id_map[3], id_map[2]) << std::endl;	

	nl();
	int d = get_diameter(g);
	std::cout << d << std::endl;
	
	nl();
	std::cout << "Num of 2-edge paths = " << get_num_of_2_edge_paths(g) << std::endl;

	nl();
	std::cout << "Triangle Count = " << get_num_of_triangles(g) << std::endl;
	return 0;
}
