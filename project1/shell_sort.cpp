#include "project1.h"

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps)
{
//	int g = gaps.size();
	int size = nums.size();
	for (int gap = size / 2; gap > 0; gap /= 2)
		for (int i = gap; i < size; ++i)
		{
			int temp = nums[i];
			int j = i;
			while (j >= gap && temp < nums[j - gap])
			{
				nums[j] = nums[j - gap];
				j -= gap;
			}
			nums[j] = temp;
		}

}
