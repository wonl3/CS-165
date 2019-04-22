#include <iostream>
#include <chrono>
#include <random>
#include <vector>

using namespace std;

mt19937 get_mersenne_twister_generator_with_current_time_seed()
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    return mt19937(seed);
}

void print_mt_random_numbers(mt19937 mt, int n)
{
    for(int i = 0; i < n; i++)
        cout << mt() << "\n";
}

uniform_int_distribution<int> get_uniform_int_generator(int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub);
}

void print_mt_bounded_numbers(mt19937 mt, uniform_int_distribution<int> ui, int n)
{
    for(int i = 0; i < n; i++)
        cout << ui(mt) << "\n";
}

int randint(mt19937 mt, int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub)(mt);
}

void shuffle_vector(vector<int>& nums)
{
    // Uses Fisher-Yates
    // CODE REMOVED
    // Write your own implementation using slides from class
}

/*
int main()
{
    mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

    print_mt_random_numbers(
        mt,
        10
    );


    cout << "\n";

    uniform_int_distribution<int> ui = get_uniform_int_generator(-4, 8);
    print_mt_bounded_numbers(mt, ui, 20);

    cout << "\n";
    for(int i = 0; i < 10; i++)
        cout << randint(mt, 0, i) << "\n";

    cout << "\n";
    vector<int> nums = {1, 2, 3, 4, 5};
    for(int i = 0; i < 10; i++)
    {
        shuffle_vector(nums);
        for(int num : nums)
            cout << num << " ";
        cout << "\n";
    }
    return 0;
}
*/
