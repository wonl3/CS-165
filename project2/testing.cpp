#include "project2.h"
#include "next_fit.cpp"
#include "first_fit.cpp"
#include "best_fit.cpp"

struct Waste
{
	int n;
	double w;

	Waste()
	{
		n = 0;
		w = 0.0;
	}

	Waste(int m, double v)
	{
		n = m;
		w = v;
	}
};

void create_empty_waste_file(std::string filename)
{
	std::ofstream f;
	f.open(filename, std::ios::trunc);
	f << "funcname,n,waste\n";
	f.close();
}

void add_waste(std::string funcname, Waste waste, std::string filename)
{
	std::ofstream f;
	f.open(filename, std::ios::app);
	f << funcname << "," << waste.n << "," << waste.w << "\n";
	f.close();
}

Waste best_fit_dec_waste(int n, int reps)
{
	double total_waste = 0.0;
	std::vector<double> items;

	for (int i = 0; i < reps; ++i)
	{
		items = {0.5, 0.7, 0.5, 0.2, 0.4, 0.2, 0.5, 0.1, 0.6};
		std::vector<int> assignment(items.size(), 0);
		std::vector<double> free_space;

		best_fit_decreasing(items, assignment, free_space);
		print_vector(assignment);
		print_vector(free_space);
		total_waste += (free_space.size() - get_sum(items));
	}
	
	Waste waste(n, (float)total_waste/reps);
	return waste;
}

