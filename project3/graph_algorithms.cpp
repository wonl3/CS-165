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

int get_index_of_nonempty_vector(std::vector<std::vector<int>>& D)
{
	for (int i = 1; i < D.size(); ++i)
	{
		if (D[i].size() != 0) return i;
	}
	
	return 0;
}

std::vector<int> get_degeneracy_ordering(Graph graph, std::vector<std::vector<int>> N)
{
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	std::vector<int> L;
	std::set<int> HL;

	//compute dv for each vertex
	std::vector<int> dv_list(graph.get_num_nodes() + 1, 0);
	int max_dv = 0;
	for (int i = 1; i < dv_list.size(); ++i)
	{
		dv_list[i] = id_to_node_map[i].neighbors.size();
 		max_dv = std::max(max_dv, id_to_node_map[i].neighbors.size());
	//	if (max_dv < id_to_node_map[i].neighbors.size())
	//		max_dv = id_to_node_map[i].neighbors.size();
	}

	std::vector<std::vector<int>> D(max_dv + 1, std::vector<int>{});
	for (int i = 1; i < max_dv + 1; ++i)
	{
		D[dv_list[i]].push_back(i);
	}

	int k = 0;

	for (int i = 0; i < graph.get_num_nodes(); ++i)
	{
		int j = get_smallest_index_of_nonempty_vector(D);
		if (j == 0)
		{
			std::cout << "Error.\n";
			exit(1);
		}

		k = std::max(k, j);
		int v = D[i][D[i].size()-1];
		D[i].pop_back();
		L.push_back(v);
		HL.insert(v);

		Node n = id_to_node_map[v];
		for (int t = 0; t < n.neighbors.size(); ++t)
		{
			if (HL.find(n.neighbors[t]) != HL.end()) continue;
			std::vector<int>::iterator it = find(D[dv_list[n.neighbors[t]]].begin(). D[dv_list[n.neighbors[t]]].end(), t);
			D[dv_list[n.neighbors[t]]].erase(it);
			
			--dv_list[n.neighbors[t]];
			D[dv_list[n.neighbors[t]]].push_back(n.neighbors[t]);
			N[v].push_back(n.neighbors[t]);
		}
	}

//	reverse(L);
}

int get_num_of_triangles(Graph graph)
{
	return 0;
}

int get_num_of_2_edge_paths(Graph graph)
{
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	int sum = 0;

	for (std::map<int, Node>::iterator it = id_to_node_map.begin(); it != id_to_node_map.end(); ++it)
	{
		int degree = (it->second).neighbors.size();
		sum += (degree * (degree - 1) / 2);
	}

	return sum;
}

// Returns a vector of 2 ints - {eccentricity of node, node id of the farthest node}
std::vector<int> bfs(Graph graph, int node_id)
{	
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	
	if (id_to_node_map[node_id].neighbors.size() == 0)
	{
		std::cout << "hi" << std::endl;
		return std::vector<int>{0, 0};
	}

	std::vector<int> v(2, 0);
	std::set<int> explored;
	std::queue<int> q;
	q.push(node_id);
	explored.insert(node_id);

	while(!q.empty())
	{
		bool new_neighbor = false;
		int n_id = q.front();
		q.pop();
		Node n = id_to_node_map[n_id];

		for (int i = 0; i < n.neighbors.size(); ++i)
		{
			std::cout << "n.neighbors[i] = " << n.neighbors[i] << std::endl;
			if (explored.find(n.neighbors[i]) == explored.end())
			{
				std::cout << "Node " << n.neighbors[i] << " found in Node " << n_id << std::endl;
				new_neighbor = true;
				q.push(n.neighbors[i]);
				v[1] = n.neighbors[i];
			}
		}

		explored.insert(n_id);

		if (new_neighbor)
			++v[0];
	}
	
	return v;
}

int get_diameter(Graph graph)
{
	int diameter = 0;
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();	
	int current_node = 1;

	while (true)
	{
		std::vector<int> v = bfs(graph, current_node);
		std::cout << "v[0] = " << v[0] << ", v[1] = " << v[1] << std::endl;
		if (v[0] <= diameter)
			break;
		std::cout << "new diameter = " << v[0] << ", current node = " << v[1] << std::endl;
		diameter = v[0];
		current_node = v[1];
	}

	return diameter;
}

float get_clustering_coefficient(Graph graph)
{
	int num_of_2_edge_paths = get_num_of_2_edge_paths(graph);
	int num_of_triangles = get_num_of_triangles(graph);

	return 3 * ((float) num_of_triangles) / num_of_2_edge_paths;
}

std::map<int, int> get_degree_distribution(Graph graph)
{
	std::map<int, int> deg_dis;

	for (std::map<int, Node>::iterator it = graph.get_id_to_node_map().begin(); it != graph.get_id_to_node_map().end(); ++it)
	{
		++deg_dis[(it->second).get_degree()];
	}

	return deg_dis;
}

