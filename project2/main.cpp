#include "testing.cpp"

int main()
{

/*
	std::vector<double> items = {0.5, 0.7, 0.5, 0.2, 0.4, 0.2, 0.5, 0.1, 0.6};
	std::vector<int> assignment(items.size(), 0);
	std::vector<double> free_space;

	next_fit(items, assignment, free_space);
	first_fit(items, assignment, free_space);
	first_fit_decreasing(items, assignment, free_space);
	best_fit(items, assignment, free_space);
	best_fit_decreasing(items, assignment, free_space);
	
	print_vector(assignment);
	print_vector(free_space);
*/	

	create_empty_waste_file("best_fit_dec.csv");
	Waste waste = best_fit_dec_waste(9, 1);
	add_waste("best_fit_dec", waste, "best_fit_dec.csv");

	return 0;
}
