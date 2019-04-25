#include "project1.h"
#include <cmath>

std::vector<int> make_gaps(int n)
{
	int init_gaps[] = {1,4,10,23,57,132,301,701};
	int gap_arr[n/2];
	int i, gap = (int) floor(2.25 * 701);
	for (i = 0; i < 8; ++i)
	{
		if (n < init_gaps[i] * 2)
			break;
		gap_arr[i] = init_gaps[i];
	}

	while (n >= gap * 2)
	{
		gap_arr[i++] = gap;
		gap = (int) floor(2.25 * gap);
	}
	
	std::vector<int> gaps = std::vector<int>(i);
	for (int j = 0; j < i; ++j)
		gaps[j] = gap_arr[i-1-j];

	return gaps;
}

void shell_sort_halved(std::vector<int>& nums)
{
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

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps)
{
	if (gaps.size() == 0)
		shell_sort_halved(nums);

	int size = nums.size(), g = gaps.size();
	
	for (int k = 0; k < g; ++k)
	{
		int gap = gaps[k];
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
}


