#include "project1.h"

void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int t = temps.size(), n = nums.size();
	for (int j = 0; j < t; ++j)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			for (int k = 0; k < reps[j]; ++k)
			{
//				std::cout << "Here\n";
				int m = std::min(n, i + temps[j]);
				std::uniform_int_distribution<> dis((i + 1), m);
//				int s = (mt() % (m - i)) + (i + 1);
//				if (s > m) s = m;

				int s = dis(gen);
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
				std::uniform_int_distribution<> dis(m, (i - 1));
//				int s = (mt() % (i - m)) + m;
//				if (s > i - 1) s = i - 1;

				int s = dis(gen);
//				std::cout << m << ", " << i - 1 << ", " << s << std::endl;
				if (nums[s] > nums[i])
					swap(nums, i, s);
			}
		}
	}
}
