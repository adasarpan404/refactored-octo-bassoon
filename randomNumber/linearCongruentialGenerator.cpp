#include <iostream>

using namespace std;
unsigned long int lcg_rand(unsigned int seed)
{
    const unsigned long int a = 1664525;
    const unsigned long int c = 10139004223;
    const unsigned long int m = 100;
    static unsigned long int current_seed = seed;

    current_seed = (a * current_seed + c) % m;

    return current_seed;
}

int main()
{
    unsigned int seed = 12345;

    for (int i = 0; i < 10; i++)
    {
        unsigned long int rand_num = lcg_rand(seed);
        cout << rand_num << endl;
        seed = rand_num;
    }
    return 0;
}