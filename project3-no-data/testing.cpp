#include "erdos_renyi.cpp"

void create_empty_diameter_file()
{
	std::ofstream f;
	f.open("diameter.csv", std::ios::trunc);
	f << "n,d\n";
	f.close();
}

void add_diameter(int n, double d)
{
	std::ofstream f;
	f.open("diameter.csv", std::ios::app);
	f << n << "," << d << "\n";
	f.close();
}

void create_empty_clustering_coeff_file()
{
	std::ofstream f;
	f.open("clustering_coefficient.csv", std::ios::trunc);
	f << "n,c\n";
	f.close();
}

void add_clustering_coeff(int n, double c)
{
	std::ofstream f;
	f.open("clustering_coefficient.csv", std::ios::app);
	f << n << "," << c << "\n";
	f.close();
}

void create_empty_deg_dis_file(std::string n)
{
	std::string file = "degree_distribution_";
	file.append(n);
	std::ofstream f;
	f.open(file, std::ios::trunc);
	f << "degree,freq\n";
	f.close();
}

void add_deg_dis(std::string file, int n, std::map<int, int>& deg_dis)
{
	std::ofstream f;
	f.open(file, std::ios::app);

	for (int i = 0; i < n; ++i)
		f << i << "," << deg_dis[i] << "\n";

	f.close();
}


