#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "spin_the_bottle_sort.cpp"
#include "shell_sort.cpp"
#include "annealing_sort.cpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <string>
#include <cmath>

struct timing
{
	int n;
	double seconds;

	timing()
	{
		n = 0;
		seconds = 0.0;
	}

	timing(int m, double s)
	{
		n = m;
		seconds = s;
	}
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

void create_empty_timing_file(std::string filename)
{
	std::ofstream f;
	f.open(filename, std::ios::trunc);
	f << "funcname,n,seconds\n";
	f.close();
}

void add_timing(std::string funcname, timing t, std::string filename)
{
	std::ofstream f;
	f.open(filename, std::ios::app);
	f << funcname << "," << t.n << "," << t.seconds << "\n";
	f.close();
}

// Uniformly Distributed Vector Sortings

timing uniform_bs_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v;
	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		std::clock_t start_time = clock();
		bubble_sort(v);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing uniform_is_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v;
	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		std::clock_t start_time = clock();
		insertion_sort(v);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing uniform_stbs_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v;
	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		std::clock_t start_time = clock();
		spin_the_bottle_sort(v);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing uniform_ss_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, gaps;
	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		std::clock_t start_time = clock();
		shell_sort(v, gaps);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

// Nearly Sorted Vector Sortings

timing nearly_sorted_bs_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v;
	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		std::clock_t start_time = clock();
		bubble_sort(v);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing nearly_sorted_is_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v;
	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		std::clock_t start_time = clock();
		insertion_sort(v);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing nearly_sorted_stbs_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v;
	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		std::clock_t start_time = clock();
		spin_the_bottle_sort(v);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing nearly_sorted_ss_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, gaps;
	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		std::clock_t start_time = clock();
		shell_sort(v, gaps);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

