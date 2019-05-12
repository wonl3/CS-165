#include "project2.h"

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	free_space.push_back(1.0);
	for (int i = 0; i < size; ++i)
	{
		// if next bin content + current item > 1.0 
		if (free_space[free_space.size() - 1] - items[i] < 0.0)
		{
			free_space.push_back(1.0 - items[i]);
			assignment[i] = free_space.size() - 1;
		}
		else
		{
			free_space[free_space.size() - 1] -= items[i];
			assignment[i] = free_space.size() - 1; 
		}
	}

	limit_decimal_point(free_space, 4);
}
