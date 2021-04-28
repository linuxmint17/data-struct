#include <iostream>
#include <random>
#include <vector>
#include "utils.h"

template <typename T>
void bubble_sort(std::vector<T> &array)
{
    unsigned int sz = array.size();
    for (unsigned int i = 0; i < sz - 1; i++) { // 循环的次数 sz - 1 次数
        for (unsigned int j = 0; j < sz - 1 - i; j++) {
            if (array[j] < array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

int main()
{
    std::vector<int> array;
    std::uniform_int_distribution<int> distribution(-50, 50);

    std::random_device rand_dev; // uses RDRND or /dev/urandom
    for (int i = 0; i < 10; i++) {
        array.push_back(distribution(rand_dev));
    }

    std::cout << std::endl;
    print_array(array);
    bubble_sort(array);
    print_array(array);

    return 0;
}
