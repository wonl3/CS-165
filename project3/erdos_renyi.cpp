#include "project3.h"
#include "graph_algorithms.cpp"


Graph create_erdos_renyi_graph(int n, float p)
{
	Graph graph = make_graph(n, std::vector<int>{}, std::vector<int>{});
	int v = 1, w = -1;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);
	//dis(gen);
	
	while (v < n)
	{
		double r = dis(gen);
		w += 1 + floor(log(1-r)/log(1-p));
		while (w >= v && v < n)
		{
			w -= v;
			++v;
		}

		if (v < n)
			graph.add_edge(v, w);
	}

	return graph;
}
