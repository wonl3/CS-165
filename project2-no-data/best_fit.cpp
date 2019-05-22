#include "project2.h"


void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	free_space.push_back(1.0);

	for (int i = 0; i < size; ++i)
	{
		//round off each item to seventh digit place to avoid subtraction precision
		double item_rounded = limit_decimal_point(items[i], 7);

		int tightest_bin = -1;
//		double min_space = 1;
		int fs_size = free_space.size();
		for (int j = 0; j < fs_size; ++j)
		{
			// Check if the current bin can fit the current item
			if (free_space[j] - item_rounded >= 0.0)
			{
				// If yes and tightest_bin hasn't been set yet, set it to index of current bin
				if (tightest_bin == -1)
					tightest_bin = j;
				else // If tightest_bin has been set already, compare the free_space of the two bins and set it to the smaller one
					if (free_space[j] < free_space[tightest_bin])
						tightest_bin = j;
			}
		}
		
		// If tightest_bin has still not been updated (a.k.a no bin can fit the item), make a new bin
		if (tightest_bin == -1)
		{
			free_space.push_back(1.0 - item_rounded);
			++fs_size;
			assignment[i] = fs_size - 1;
		}
		// Else, put it into the tightest bin
		else
		{
			free_space[tightest_bin] -= item_rounded;
			assignment[i] = tightest_bin;
		}
	}

	round_decimal(free_space, 7);	
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double> sorted_items(items);
	// Sort in Desc order
	std::sort(sorted_items.begin(), sorted_items.end(), std::greater<double>());

	best_fit(sorted_items, assignment, free_space);
}
