#include <iostream>
#include "timing.cpp"

int main()
{
//	std::vector<int> tv;
//	tv = get_random_vector(100);
//	print(tv);	
//	bubble_sort(nums);	// works
//	insertion_sort(nums);	// works
//	spin_the_bottle_sort(nums);	//works
//	shell_sort(nums); //works
	
	create_empty_timing_file("uniform_timings.csv");
	create_empty_timing_file("nearly_sorted_timings.csv");
	timing t;

// Uniform

	// Bubble Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = uniform_bs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("bubble_sort", t, "uniform_timings.csv");
		std::cout << "Bubble Sort -  Size " << n << " Done" << std::endl;
	}

	// Insertion Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = uniform_is_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("insertion_sort", t, "uniform_timings.csv");
		std::cout << "Insertion Sort - Size " << n << " Done" << std::endl;
	}

	// Spin-the-bottle Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = uniform_stbs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("spin_the_bottle_sort", t, "uniform_timings.csv");
		std::cout << "Spin-the-bottle Sort - Size " << n << " Done" << std::endl;
	}

	// Shell Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = uniform_ss_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("shell_sort", t, "uniform_timings.csv");
		std::cout << "Shell Sort - Size " << n << " Done" << std::endl;
	}


// Nearly Sorted

	// Bubble Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = nearly_sorted_bs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("bubble_sort", t, "nearly_sorted_timings.csv");
		std::cout << "Bubble Sort -  Size " << n << " Done" << std::endl;
	}

	// Insertion Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = nearly_sorted_is_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("insertion_sort", t, "nearly_sorted_timings.csv");
		std::cout << "Insertion Sort - Size " << n << " Done" << std::endl;
	}

	// Spin-the-bottle Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = nearly_sorted_stbs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("spin_the_bottle_sort", t, "nearly_sorted_timings.csv");
		std::cout << "Spin-the-bottle Sort - Size " << n << " Done" << std::endl;
	}

	// Shell Sort
	for (int n = 10; n <= 1000; n *= 10)
	{
		t = nearly_sorted_ss_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("shell_sort", t, "nearly_sorted_timings.csv");
		std::cout << "Shell Sort - Size " << n << " Done" << std::endl;
	}

	return 0;
}
