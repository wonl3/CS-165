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

void create_empty_timings()
{
//	create_empty_timing_file("timings/uniform_bs_timings.csv");
//	create_empty_timing_file("timings/uniform_is_timings.csv");
//	create_empty_timing_file("timings/uniform_stbs_timings.csv");
//	create_empty_timing_file("timings/uniform_ss_1_timings.csv");
//	create_empty_timing_file("timings/uniform_ss_2_timings.csv");
//	create_empty_timing_file("timings/uniform_as_1_timings.csv");
	create_empty_timing_file("timings/uniform_as_2_timings.csv");

//	create_empty_timing_file("timings/nearly_sorted_bs_timings.csv");
//	create_empty_timing_file("timings/nearly_sorted_is_timings.csv");
//	create_empty_timing_file("timings/nearly_sorted_stbs_timings.csv");
//	create_empty_timing_file("timings/nearly_sorted_ss_1_timings.csv");
//	create_empty_timing_file("timings/nearly_sorted_ss_2_timings.csv");
//	create_empty_timing_file("timings/nearly_sorted_as_1_timings.csv");
	create_empty_timing_file("timings/nearly_sorted_as_2_timings.csv");
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

timing uniform_ss_1_sorting_time(int n, int reps)
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

timing uniform_ss_2_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, gaps;
	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		gaps = make_gaps(n);
		//print(gaps);
		std::clock_t start_time = clock();
		shell_sort(v, gaps);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing uniform_as_1_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, temp, rep;
	temp = get_log2_rev_vector(n);
	rep = get_log2_rev_vector(n);

	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		std::clock_t start_time = clock();
		annealing_sort(v, temp, rep);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing uniform_as_2_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, temp, rep;
	temp = get_log2_rev_vector(n);
	rep = get_c_vector(n, (int) log2(n));

	for (int i = 0; i < reps; ++i)
	{
		v = get_random_vector(n);
		std::clock_t start_time = clock();
		annealing_sort(v, temp, rep);
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

timing nearly_sorted_ss_1_sorting_time(int n, int reps)
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

timing nearly_sorted_ss_2_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, gaps;
	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		gaps = make_gaps(n);
		//print(gaps);
		std::clock_t start_time = clock();
		shell_sort(v, gaps);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing nearly_sorted_as_1_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, temp, rep;
	temp = get_log2_rev_vector(n);
	rep = get_log2_rev_vector(n);
	
	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		std::clock_t start_time = clock();
		annealing_sort(v, temp, rep);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}

timing nearly_sorted_as_2_sorting_time(int n, int reps)
{
	double total_time = 0.0;
	std::vector<int> v, temp, rep;
	temp = get_log2_rev_vector(n);
	rep = get_c_vector(n, (int)log2(n));

	for (int i = 0; i < reps; ++i)
	{
		v = get_nearly_sorted_vector(n);
		std::clock_t start_time = clock();
		annealing_sort(v, temp, rep);
		std::clock_t end_time = clock();
		total_time += (float)(end_time - start_time) / CLOCKS_PER_SEC;
	}
	timing t(n, (float)total_time/reps);
	return t;
}
