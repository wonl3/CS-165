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

std::vector<int> get_random_vector(int n)
{
	std::vector<int> v = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		v[i] = (i + 1);
	shuffle_vector(v);
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

timing sorting_time(int n, int reps)
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


int main()
{
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(10);
	nums.push_back(9);

	std::vector<int> gaps;
	gaps.push_back(2);
	
	// Testing random_shuffle	works
//	std::vector<int> tv;
//	tv = get_random_vector(100);
//	print(tv);	
//	bubble_sort(nums);	// works
//	insertion_sort(nums);	// works
//	spin_the_bottle_sort(nums);	//works
//	shell_sort(nums); //works

	
	create_empty_timing_file("timings.csv");
	timing t;
	for (int n = 10; n <= 100000; n *= 10)
	{
		t = sorting_time(n, 3);
		std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("bubble_sort", t, "timings.csv");
		std::cout << "size " << n << " Done" << std::endl;
	}

	return 0;
}
