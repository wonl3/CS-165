#include "project2.h"

void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	free_space.push_back(1.0);
	
	for (int i = 0; i < size; ++i)
	{
		//round off each item to seventh decimal place for now
		double item_rounded = limit_decimal_point(items[i], 7);
		
		// if next bin content + current item > 1.0 
		if (free_space[free_space.size() - 1] - item_rounded < 0.0)
		{
			free_space.push_back(1.0 - item_rounded);
			assignment[i] = free_space.size() - 1;
		}
		else
		{
			free_space[free_space.size() - 1] -= item_rounded;
			assignment[i] = free_space.size() - 1; 
		}
	}

	round_decimal(free_space, 7);
}
