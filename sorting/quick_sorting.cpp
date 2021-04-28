#include <iostream>
#include <random>
#include <vector>
#include "utils.h"
// 7 2 1 6 8 5 3 4
template <typename T>
int partation(std::vector<T> &array, int start, int end)
{
    T pivot = array[end];
    int PIndex = start;
    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            swap(array[i], array[PIndex]);
            PIndex++;
        }
    }
    swap(array[PIndex], array[end]);
    return PIndex;
}

template <typename T>
int partation2(std::vector<T> &array, int start, int end)
{
    T pivot = array[end];
    int PIndex = start;
    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            swap(array[i], array[PIndex]);
            PIndex++;
        }
    }
    swap(array[PIndex], array[end]);
    return PIndex;
}
//严蔚敏《数据结构》标准分割函数
 int Paritition1(int A[], int low, int high) {
   int pivot = A[low];
   while (low < high) {
     while (low < high && A[high] >= pivot) {
       --high;
     }
     A[low] = A[high];
     while (low < high && A[low] <= pivot) {
       ++low;
     }
     A[high] = A[low];
   }
   A[low] = pivot;
   return low;
 }

template <typename T>
void quick_sort(std::vector<T> &array, int start, int end)
{
    if (start < end) { // 数组下标变化的会发生 start > end的情况, 如果数组只有一个元素，就会出现相等的情况
        int pIndex = partation(array, start, end);
        quick_sort(array, start, pIndex - 1);
        quick_sort(array, pIndex + 1, end);
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
    quick_sort(array, 0, array.size() - 1);
    print_array(array);

    return 0;
}