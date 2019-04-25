#include "project1.h"

/*
void find_pos(std::vector<int>& nums, int i, int gap)
{
	int temp = nums[i];

	while (i > 0 && temp <= nums[i - gap])
	{
//		std::cout << "Comparing " << nums[i] << " and " << nums[i - gap] << std::endl;
		nums[i] = nums[i - gap];
		i -= gap;
	}
	
	nums[i] = temp;
}
*/

void insertion_sort(std::vector<int>& nums)
{
	int size = nums.size();
	for (int i = 1; i < size; ++i)
	{
		int temp = nums[i];
		int j = i;
		while (j > 0 && temp < nums[j-1])
		{
			nums[j] = nums[j-1];
			--j;
		}
		nums[j] = temp;
	}
}

/*
//for shell sort
void insertion_sort_with_gap(std::vector<int>& nums, int gap)
{
	if (gap == 1)
	{
		insertion_sort(nums);
		return;
	}

	int size = nums.size();
	for (int i = 0; i < gap; ++i)
	{
		for (int j = i + gap; j < size; j += gap)
		{
			find_pos(nums, j, gap);
		}
	}
}
*/
