#include <iostream>
#include <random>
#include <vector>

namespace {
template <typename T>
void print_array(std::vector<T> &array)
{
    for (auto it = array.begin(); it != array.end(); it++) {
        std::cout << *it << '\t';
    }
    std::cout << '\n';
}

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

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
}
int main()
{
    std::vector<int> array;
    std::uniform_int_distribution<int> distribution(-50, 50);

    std::random_device rand_dev; // uses RDRND or /dev/urandom
    for (int i = 0; i < 1000; i++) {
        array.push_back(distribution(rand_dev));
    }

    std::cout << std::endl;
    print_array(array);
    bubble_sort(array);
    print_array(array);

    return 0;
}