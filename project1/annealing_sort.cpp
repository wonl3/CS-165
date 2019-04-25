#include "project1.h"

void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps)
{
	std::mt19937 mt = get_seed();
	int t = temps.size(), n = nums.size();
	for (int j = 0; j < t; ++j)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int k = 0; k < reps[j]; ++k)
			{
//				std::cout << "Here\n";
				int m = std::min(n, i + temps[j]);
				int s = (mt() % (m - i)) + (i + 1);
				if (s > m) s = m;

//				std::cout << i + 1 << ", " << m << ", " << s << std::endl;
				if (nums[i] > nums[s])
					swap(nums, i, s);
			}
		}
		
		for (int i = n - 1; i > 1; --i)
		{
			for (int k = 0; k < reps[j]; ++k)
			{
//				std::cout << "Hi\n";
				int m = std::max(1, i - temps[j]);
				int s = (mt() % (i - m)) + m;
				if (s > i - 1) s = i - 1;

//				std::cout << m << ", " << i - 1 << ", " << s << std::endl;
				if (nums[s] > nums[i])
					swap(nums, i, s);
			}
		}
	}
}
