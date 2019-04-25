#ifndef PROJECT1_H
#define PROJECT1_H

#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

// Helper Functions

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

void swap(std::vector<int>& nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void print(std::vector<int>& nums)
{
	int i = 0;
	for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
		std::cout << nums[i++] << std::endl;
}

bool check_sorted(std::vector<int>& nums)
{
	int size = nums.size();
	for (int i = 1; i < size; ++i)
		if (nums[i] < nums[i-1])
			return false;
	return true;
}

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

void shuffle_vector_2(std::vector<int>& v)
{
	int size = v.size();
	int number_of_swaps = 2 * (int) (log2((double) size));
	std::mt19937 mt = get_seed();

	for (int i = 0; i < number_of_swaps; ++i)
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

std::vector<int> get_nearly_sorted_vector(int n)
{
	std::vector<int> v = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		v[i] = (i + 1);
	shuffle_vector_2(v);
	return v;
}

std::vector<int> get_log2_rev_vector(int n)
{
	int lg2 = (int) log2(n);
	std::vector<int> v = std::vector<int>(lg2 + 2);
	v[0] = n;
	for (int i = 1; i < lg2 + 1; ++i)
	{
		v[i] = n / 2;
		n /= 2;
	}
	v[lg2 + 1] = 0;

	return v;
}

//REQUIREMENTS:
//each sort should be implemented in its own file of the same name e.g. bubble_sort.cpp
//each file should #include this header file
//no file should use anything outside of the C++ standard library
//functions should be tested using g++ in a linux environment
//each function should modify the input vector so that it is sorted upon completion
void bubble_sort(std::vector<int>& nums);
void insertion_sort(std::vector<int>& nums);
void spin_the_bottle_sort(std::vector<int>& nums);
void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps);
void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps);

#endif
