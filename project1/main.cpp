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
	
//	create_empty_timing_file("uniform_timings.csv");
//	create_empty_timing_file("nearly_sorted_timings.csv");
	create_empty_timings();
	timing t;

///*
// Uniform

	// Bubble Sort
	for (int n = 10; n <= 100000; n *= 10)
	{
		t = uniform_bs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("bubble_sort", t, "timings/uniform_bs_timings.csv");
		std::cout << "Bubble Sort -  Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}

	// Insertion Sort
	for (int n = 10; n <= 100000; n *= 10)
	{
		t = uniform_is_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("insertion_sort", t, "timings/uniform_is_timings.csv");
		std::cout << "Insertion Sort - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}

	// Spin-the-bottle Sort
	for (int n = 4; n <= 2500; n *= 5)
	{
		t = uniform_stbs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("spin_the_bottle_sort", t, "timings/uniform_stbs_timings.csv");
		std::cout << "Spin-the-bottle Sort - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}

	// Shell Sort 1
	for (int n = 10; n <= 1000000; n *= 10)
	{
		t = uniform_ss_1_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("shell_sort", t, "timings/uniform_ss_1_timings.csv");
		std::cout << "Shell Sort 1 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
	// Shell Sort 2
	for (int n = 10; n <= 1000000; n *= 10)
	{
		t = uniform_ss_2_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("shell_sort", t, "timings/uniform_ss_2_timings.csv");
		std::cout << "Shell Sort 2 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
//*/

	// Annealing Sort 1
	for (int n = 10; n <= 10000; n *= 10)
	{
		t = uniform_as_1_sorting_time(n, 3);
		add_timing("annealing_sort", t, "timings/uniform_as_1_timings.csv");
		std::cout << "Annealing Sort 1 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
/*
	// Annealing Sort 2
	for (int n = 10; n <= 10000; n *= 10)
	{
		t = uniform_as_2_sorting_time(n, 3);
		add_timing("annealing_sort", t, "timings/uniform_as_1_timings.csv");
		std::cout << "Annealing Sort 1 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
*/
///*
// Nearly Sorted

	// Bubble Sort
	for (int n = 10; n <= 100000; n *= 10)
	{
		t = nearly_sorted_bs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("bubble_sort", t, "timings/nearly_sorted_bs_timings.csv");
		std::cout << "Bubble Sort -  Size: " << n << " Time: " << t.seconds << "  Done" << std::endl;
	}

	// Insertion Sort
	for (int n = 10; n <= 100000; n *= 10)
	{
		t = nearly_sorted_is_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("insertion_sort", t, "timings/nearly_sorted_is_timings.csv");
		std::cout << "Insertion Sort - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}

	// Spin-the-bottle Sort
	for (int n = 4; n <= 2500; n *= 5)
	{
		t = nearly_sorted_stbs_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("spin_the_bottle_sort", t, "timings/nearly_sorted_stbs_timings.csv");
		std::cout << "Spin-the-bottle Sort - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}

	// Shell Sort 1
	for (int n = 10; n <= 1000000; n *= 10)
	{
		t = nearly_sorted_ss_1_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("shell_sort", t, "timings/nearly_sorted_ss_1_timings.csv");
		std::cout << "Shell Sort 1 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}

	// Shell Sort 2
	for (int n = 10; n <= 1000000; n *= 10)
	{
		t = nearly_sorted_ss_2_sorting_time(n, 3);
		//std::cout << "Size " << t.n << ", Time: " << t.seconds << std::endl;
		add_timing("shell_sort", t, "timings/nearly_sorted_ss_2_timings.csv");
		std::cout << "Shell Sort 2 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
//*/
	// Annealing Sort 1
	for (int n = 10; n <= 10000; n *= 10)
	{
		t = nearly_sorted_as_1_sorting_time(n, 3);
		add_timing("annealing_sort", t, "timings/nearly_sorted_as_1_timings.csv");
		std::cout << "Annealing Sort 1 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
/*
	// Annealing Sort 2
	for (int n = 10; n <= 10000; n *= 10)
	{
		t = nearly_sorted_as_2_sorting_time(n, 3);
		add_timing("annealing_sort", t, "timings/nearly_sorted_as_2_timings.csv");
		std::cout << "Annealing Sort 2 - Size: " << n << " Time: " << t.seconds << " Done" << std::endl;
	}
*/
	return 0;
}
