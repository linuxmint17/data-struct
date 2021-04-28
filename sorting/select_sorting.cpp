#include <iostream>
#include <random>
#include <vector>
#include "utils.h"

template <typename T>
void select_sort(std::vector<T> &array)
{
    unsigned int sz = array.size();
    unsigned int max_idx;
    for (unsigned int i = 0; i < sz; i++) {
        max_idx = i;
        for (unsigned int j = i + 1; j < sz; j++) {
            if (array[max_idx] < array[j]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(array[max_idx], array[i]);
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

    print_array(array);
    select_sort(array);
    print_array(array);

    return 0;
}