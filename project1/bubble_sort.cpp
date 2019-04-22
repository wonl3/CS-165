#include "project1.h"


void bubble_sort(std::vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size - i; ++j)
		{
//	std::cout << "Comparing: " << nums[j] << " and " << nums[j+1] << std::endl;	
			if (nums[j-1] > nums[j])
			{
				swap(nums, j-1, j);
			}
		}
	}
}
