#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "spin_the_bottle_sort.cpp"
#include "shell_sort.cpp"
#include "annealing_sort.cpp"
#include <iostream>

int main()
{
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(10);
	nums.push_back(9);

	std::vector<int> gaps;
	gaps.push_back(2);

//	bubble_sort(nums);	// works
//	insertion_sort(nums);	// works
//	spin_the_bottle_sort(nums);	//works
	shell_sort(nums, gaps);
	print(nums);

	return 0;
}
