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
	create_empty_waste_file("next_fit.csv");
	create_empty_waste_file("first_fit.csv");
	create_empty_waste_file("first_fit_dec.csv");
	create_empty_waste_file("best_fit.csv");
	create_empty_waste_file("best_fit_dec.csv");

	Waste waste;

	for (int n = 10; n <= 100000; n *= 10)
	{
		waste = next_fit_waste(n, 2);
		add_waste("next_fit", waste, "next_fit.csv");
		std::cout << "next_fit - Size: " << n << ", Waste: " << waste.w << std::endl;
	}

	for (int n = 10; n <= 100000; n *= 10)
	{
		waste = first_fit_waste(n, 2);
		add_waste("first_fit", waste, "first_fit.csv");
		std::cout << "first_fit - Size: " << n << ", Waste: " << waste.w << std::endl;
	}

	for (int n = 10; n <= 100000; n *= 10)
	{
		waste = first_fit_dec_waste(n, 2);
		add_waste("first_fit_dec", waste, "first_fit_dec.csv");
		std::cout << "first_fit_dec - Size: " << n << ", Waste: " << waste.w << std::endl;
	}

	for (int n = 10; n <= 100000; n *= 10)
	{
		waste = best_fit_waste(n, 2);
		add_waste("best_fit", waste, "best_fit.csv");
		std::cout << "best_fit - Size: " << n << ", Waste: " << waste.w << std::endl;
	}

	for (int n = 10; n <= 100000; n *= 10)
	{
		waste = best_fit_dec_waste(n, 2);
		add_waste("best_fit_dec", waste, "best_fit_dec.csv");
		std::cout << "best_fit_dec - Size: " << n << ", Waste: " << waste.w << std::endl;
	}
	return 0;
}
