#include "project1.h"

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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, size - 1);
	while (true)
	{
		int i = dis(gen), j = dis(gen);
//		int i = mt() % size, j = mt() % size;
//		std::cout << "Swapping " << nums[i] << " and " << nums[j] << std::endl;
		if (i < j && nums[i] > nums[j])
			swap(nums, i, j);
		else if (i > j && nums[i] < nums[j])
			swap(nums, i, j);
		if (check_sorted(nums))
			return;
	}
} 
