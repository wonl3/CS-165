#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "spin_the_bottle_sort.cpp"
#include "shell_sort.cpp"
#include "annealing_sort.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

struct timing
{
	int n;
	double seconds;
};

void shuffle_vector(std::vector<int>& v)
{
	int size = v.size();
	std::mt19937 mt = get_seed();	
	
	for (int i = 0; i < size / 2; ++i)
	{
		int index1 = mt() % size, index2 = mt() % size;
		swap(v, index1, index2);
	}
}

std::vector<int> get_random_vector(int n)
{
	std::vector<int> v = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		v[i] = (i + 1);
	shuffle_vector(v);
	return v;
}

int main()
{
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(10);
	nums.push_back(9);

	std::vector<int> gaps;
	gaps.push_back(2);
	
	// Testing random_shuffle
	std::vector<int> tv;
	tv = get_random_vector(100);
	print(tv);	
//	bubble_sort(nums);	// works
//	insertion_sort(nums);	// works
//	spin_the_bottle_sort(nums);	//works
//	shell_sort(nums); //works

	return 0;
}
