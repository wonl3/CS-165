#include "project2.h"


void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int size = items.size();
	free_space.push_back(1.0);

	for (int i = 0; i < size; ++i)
	{
		//round off each item to ten thousanth for now
		double item_rounded = limit_decimal_point(items[i], 4);

		int tightest_bin = -1;
//		double min_space = 1;
		int fs_size = free_space.size();
		for (int j = 0; j < fs_size; ++j)
		{
			if (free_space[j] - item_rounded >= 0.0)
			{
				if (tightest_bin == -1)
					tightest_bin = j;
				else
					if (free_space[j] < free_space[tightest_bin])
						tightest_bin = j;
			}
		}
		
		if (tightest_bin == -1)
		{
			free_space.push_back(1.0 - item_rounded);
			++fs_size;
			assignment[i] = fs_size - 1;
		}
		else
		{
			free_space[tightest_bin] -= item_rounded;
			assignment[i] = tightest_bin;
		}
	}

	//round off to ten thousandth for now
	round_decimal(free_space, 4);	
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	std::vector<double> sorted_items(items);
	std::sort(sorted_items.begin(), sorted_items.end(), std::greater<double>());

	best_fit(sorted_items, assignment, free_space);
}
