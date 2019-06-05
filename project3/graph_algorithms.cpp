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

int get_smallest_index_of_nonempty_vector(std::vector<std::vector<int>>& D)
{
	for (int i = 0; i < D.size(); ++i)
	{
		if (D[i].size() != 0) return i;
	}
	
	return 0;
}

std::vector<int> get_degeneracy_ordering(Graph& graph, std::vector<std::vector<int>>& N)
{
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	std::vector<int> L;
	std::set<int> HL;

	//compute dv for each vertex
	std::vector<int> dv_list(graph.get_num_nodes() + 1, 0);
	//std::vector<int> dv_list;
	int max_dv = 0;
	for (int i = 1; i < dv_list.size(); ++i)
	{
		dv_list[i] = id_to_node_map[i].neighbors.size();
	//	std::cout << "Node " << i << ", Degree = " << dv_list[i] << std::endl;
 		max_dv = std::max(max_dv, (int) id_to_node_map[i].neighbors.size());
	//	if (max_dv < id_to_node_map[i].neighbors.size())
	//		max_dv = id_to_node_map[i].neighbors.size();
	}

	std::vector<std::vector<int>> D(max_dv + 1, std::vector<int>{});
	for (int i = 1; i < dv_list.size(); ++i)
	{
		D[dv_list[i]].push_back(i);
	}

//	std::cout << "Max_dv = " << max_dv << std::endl;
//	print_matrix(D);
//	std::cout << "Everything initialized in Degeneracy function.\n";

	int k = 0;

	for (int i = 0; i < graph.get_num_nodes(); ++i)
	{
		int j = get_smallest_index_of_nonempty_vector(D);
//		std::cout << "Got smallest index = " << j << std::endl;

		k = std::max(k, j);
//		std::cout << "K is now " << k << std::endl;
		int v = D[j][D[j].size()-1];
		D[j].pop_back();
		L.push_back(v);
		HL.insert(v);

//		std::cout << "Popped the last element in D[j] = " << v << std::endl;

		Node n = id_to_node_map[v];
		for (int t = 0; t < n.neighbors.size(); ++t)
		{
			if (HL.find(n.neighbors[t]) != HL.end()) continue;
//			std::cout << "n.neighbors[t] = " << n.neighbors[t] << std::endl;
//			std::vector<int>::iterator it = std::find(D[dv_list[n.neighbors[t]]].begin(), D[dv_list[n.neighbors[t]]].end(), t);
			int index = find_index(D[dv_list[n.neighbors[t]]], n.neighbors[t]);
//			std::cout << "Current Node " << n.neighbors[t] << ", " << n.neighbors[t] << " Found at index " << index << std::endl;
			D[dv_list[n.neighbors[t]]].erase(D[dv_list[n.neighbors[t]]].begin() + index);
			
			--dv_list[n.neighbors[t]];
			D[dv_list[n.neighbors[t]]].push_back(n.neighbors[t]);
			N[v].push_back(n.neighbors[t]);
//			print_matrix(D);
		}
	}

	std::reverse(L.begin(), L.end());
	return L;
}

int get_num_of_triangles(Graph& graph)
{
	int triangle_count = 0;
	std::vector<std::vector<int>> N(graph.get_num_nodes() + 1, std::vector<int>{});
	std::vector<int> L = get_degeneracy_ordering(graph, N);
//	std::cout << "Degeneracy Passed.\n";
//	print_matrix(N);
//	print_vector(L);

	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	for (int i = 0; i < L.size(); ++i)
	{
/*
		std::vector<int> v;
		for (int i = 0; i < node.neighbors.size(); ++i)
		{
			if (find_index(N[L[i]], node.neighbors[i]) != -1)
				v.push_back(node.neighbors[i]);
		}
		print_vector(v);

		if (v.size() < 2) continue;
*/
		if (N[L[i]].size() < 2) 
		{
//			std::cout << "Not enough N for node " << L[i] << std::endl;
			continue;
		}

		for (int j = 0; j < N[L[i]].size() - 1; ++j)
		{
			for (int k = j + 1; k < N[L[i]].size(); ++k)
			{
//				std::cout << "Checking if neighbors: " << N[L[i]][j] << ", " << N[L[i]][k] << std::endl;
				Node node1 = id_to_node_map[N[L[i]][j]], node2 = id_to_node_map[N[L[i]][k]];
				if (graph.is_neighbor(node1, node2))
				{
					++triangle_count;
				}
			}
		}
	}

	return triangle_count;
}

int get_num_of_2_edge_paths(Graph& graph)
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
std::vector<int> bfs(Graph& graph, int node_id)
{	
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	
	if (id_to_node_map[node_id].neighbors.size() == 0)
	{
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
	//	std::cout << n_id << " Popped.\n";
		Node n = id_to_node_map[n_id];

		for (int i = 0; i < n.neighbors.size(); ++i)
		{
		//	std::cout << "n.neighbors[i] = " << n.neighbors[i] << std::endl;
			if (explored.find(n.neighbors[i]) == explored.end())
			{
			//	std::cout << "Node " << n.neighbors[i] << " found in Node " << n_id << std::endl;
				new_neighbor = true;
				q.push(n.neighbors[i]);
				v[1] = n.neighbors[i];
				explored.insert(n.neighbors[i]);
			}
		}

//		explored.insert(n_id);

		if (new_neighbor)
		{
		//	std::cout << "new neighbor.\n";
			++v[0];
		}
	}
	
	return v;
}

int get_diameter(Graph& graph)
{
	int diameter = 0;
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();	
	int current_node = 1;

	while (true)
	{
		std::vector<int> v = bfs(graph, current_node);
	//	std::cout << "v[0] = " << v[0] << ", v[1] = " << v[1] << std::endl;
		if (v[0] <= diameter)
			break;
	//	std::cout << "new diameter = " << v[0] << ", current node = " << v[1] << std::endl;
		diameter = v[0];
		current_node = v[1];
	}

	return diameter;
}

float get_clustering_coefficient(Graph& graph)
{
	int num_of_2_edge_paths = get_num_of_2_edge_paths(graph);
	int num_of_triangles = get_num_of_triangles(graph);

	return 3 * ((float) num_of_triangles) / num_of_2_edge_paths;
}

std::map<int, int> get_degree_distribution(Graph& graph)
{
	std::map<int, Node> id_to_node_map = graph.get_id_to_node_map();
	std::map<int, int> deg_dis;

	for (int i = 0; i < graph.get_num_nodes(); ++i)
		deg_dis.insert(std::pair<int, int>{i, 0});

	for (std::map<int, Node>::iterator it = id_to_node_map.begin(); it != id_to_node_map.end(); ++it)
	{
		++deg_dis[(it->second).get_degree()];
	}

	return deg_dis;
}

