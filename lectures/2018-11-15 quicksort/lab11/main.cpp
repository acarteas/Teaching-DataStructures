#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
#include "Sorting.h"
int main(void)
{
    //srand(time(NULL));
    vector<int> numbers{};
    for (int i = 0; i < 20; i++)
    {
        numbers.push_back(rand());
    }
    vector<int> simple{ 3, 1, 6, 5, 8, 7 };
    shellSort(numbers);
}