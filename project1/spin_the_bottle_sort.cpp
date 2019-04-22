#include "project1.h"
#include <random>
#include <chrono>

std::mt19937 get_seed()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	return std::mt19937(seed);
}

void print_mt_nums(std::mt19937 mt, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << mt() << std::endl;
}

int randint(std::mt19937 mt, int lb, int ub)
{
	return std::uniform_int_distribution<int>(lb, ub)(mt);
}

void spin_the_bottle_sort(std::vector<int>& nums)
{
	int size = nums.size();

/*	while (true)
	{
		std::mt19937 mt = get_seed(), mt2 = get_seed();
		int i = randint(mt, 0, size - 1), j = randint(mt2, 0, size -1);
		std::cout << "Swapping " << nums[i] << " and " << nums[j] << std::endl;
		if (i < j && nums[i] > nums[j])
			swap(nums, i, j);
		else if (i > j && nums[i] < nums[j])
			swap(nums, i, j);
		if (check_sorted(nums))
			return;
	}
*/
	std::mt19937 mt = get_seed();
	while (true)
	{
		int i = mt() % size, j = mt() % size;
//		std::cout << "Swapping " << nums[i] << " and " << nums[j] << std::endl;
		if (i < j && nums[i] > nums[j])
			swap(nums, i, j);
		else if (i > j && nums[i] < nums[j])
			swap(nums, i, j);
		if (check_sorted(nums))
			return;
	}
} 
