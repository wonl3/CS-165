#include "project2.h"

void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	free_space.push_back(1.0);

	for (int i = 0; i < size; ++i)
	{
		int fs_size = free_space.size();
		for (int j = 0; j < fs_size; ++j)
		{
			if (free_space[j] - items[i] >= 0.0)
			{
				free_space[j] -= items[i];
				assignment[i] = j;
				break; 
			}
	
			if (j == fs_size - 1)
			{
				free_space.push_back(1.0 - items[i]);
				++fs_size;
				assignment[i] = fs_size - 1;
				break;
			}
		}
	}
	
	limit_decimal_point(free_space, 4);
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double> sorted_items(items);
	std::sort(sorted_items.begin(), sorted_items.end(), std::greater<double>());

	first_fit(sorted_items, assignment, free_space);

}
