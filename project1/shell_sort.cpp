#include "project1.h"

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps)
{
	int g = gaps.size();
	int size = nums.size();
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		insertion_sort_with_gap(nums, gap);
	}
}
