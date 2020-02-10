#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct MonsterTruck
{
    long long position;
    long long cost;
};


int main()
{
    long long n;
    std::cin >> n;
    if(n==0)
    {
        std::cout << 0;
        return 0;
    }
    MonsterTruck* trucks = new MonsterTruck[n];
    for (long long i = 0; i < n; i++)
    {
        std::cin >> trucks[i].position >> trucks[i].cost;
    }
    long long min = 10000;
    long long max = -10000;
    for (long long i = 0; i < n; i++)
    {
        if (trucks[i].position < min)
        {
            min = trucks[i].position;
        }
        if (trucks[i].position > max)
        {
            max = trucks[i].position;
        }
    }
    long long range = max - min;
    long long low = std::numeric_limits<long long>::max();
    for (long long i = 0; i <= range; i++)
    {
        long long sum = 0;
        for (long long j = 0; j < n; j++)
        {
            sum += abs((min + i) - trucks[j].position) * trucks[j].cost;
        }
        if (sum < low)
        {
            low = sum;
        }
    }
    std::cout << low;
    return 0;
}
