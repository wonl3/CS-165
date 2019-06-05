#include "project3.h"
#include "tests.h"
#include "testing.cpp"

int main()
{
/*	Node node(3);

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
*/
	run_tests();

	int reps = 1;
//	create_empty_diameter_file();
	create_empty_clustering_coeff_file();
	create_empty_deg_dis_file("1000");
	create_empty_deg_dis_file("10000");
	create_empty_deg_dis_file("100000");
/*	
	for (int n = 1000; n <= 100000; n *= 10)
	{
		int total_diameter = 0;
		double p = 2 * log(n) / n;

		for (int i = 0; i < reps; ++i)
		{
			Graph g = create_erdos_renyi_graph(n, p); 
			total_diameter += get_diameter(g);
		}

		int avg_d = total_diameter / reps; //double
		add_diameter(n, avg_d);
		std::cout << "Size = " << n << ", Diameter = " << avg_d << std::endl;
	}
*/

	for (int n = 10; n <= 100000; n *= 10)
	{
		float total_clustering_coeff = 0.0;
		double p = 2 * log(n) / n;

//		for (int i = 0; i < reps; ++i)
//		{
		Graph g = create_erdos_renyi_graph(n, p); 
		total_clustering_coeff += get_clustering_coefficient(g); 
//		}
		double avg_c = total_clustering_coeff / reps;
		add_clustering_coeff(n, avg_c);
		std::cout << "Size = " << n << ", Cluttering Coefficient = " << avg_c << std::endl;
	}

/*
	for (int n = 1000; n <= 100000; n *= 10)
	{
		double p = 2 * log(n) / n;
		Graph g = create_erdos_renyi_graph(n, p);

		std::map<int, int> deg_dis = get_degree_distribution(g);

		if (n == 1000)
			add_deg_dis("degree_distribution_1000", n, deg_dis);
		else if (n == 10000)
			add_deg_dis("degree_distribution_10000", n, deg_dis);
		else
			add_deg_dis("degree_distribution_100000", n, deg_dis);

		std::cout << "Size = " << n << ", Degree Distribution Done.\n";
	}
*/
	return 0;
}
