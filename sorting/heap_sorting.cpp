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
void siftup(std::vector<int> &heap, int value)
{
	heap.push_back(value);
	// pre index > 0  && heap(1, n - 1) ,前置条件成立
	// post heap(1, n) 后之结果
	int i = heap.size() - 1; // 浪费掉数组的第一个位置
	int parent;
	while (1) {
		if (i == 1) {
			break;
		}
		parent = i / 2;
		if (heap[parent] <= heap[i]) {
			break;
		}
		swap(heap[parent], heap[i]);
		i = parent;
	}
}
/* 使用数组定义满二叉树 */
/*
 root = 1
 value(i) = array[i]
 leftchild(i) = 2 * i
 righchild(i) = 2 * i + 1
 parent(i) = i / 2
 null(i) = (i < 1) or (i > n)
*/
void siftdown(std::vector<int> &heap)
{
  // pre heap(2, n) && n >= 0
  // post heap(1, n);
  int heap_num = heap.size() - 1; // "浪费" 了数组的第一个元素
  int i = 1;
  int child;
  while (1) {
	// invariant: heap(1, n) except perhaps between i and its (0, 1 or 2) children */
	child = 2 * i;
	if (child > heap_num) {
		break;
	}
	if (child + 1 <= heap_num) {
		// child + 1 ( 2 * i + 1)is the right child of i;
		if (heap[child + 1] < heap[child]) {
			child++; // 把 child 设置位较小的child
		}
	}
	// child is lesser than the child of i, 满足小顶堆的定义，break, 否则交换
	if (heap[i] <= heap[child]) {
		break;
	}
	swap(heap[child], heap[i]);
	i = child;
  }
}
}

int main()
{
    std::vector<int> array = {-1, 12, 20, 15, 29, 23, 17, 22, 35, 40, 51, 19};
    
    std::cout << std::endl;
    print_array(array);
    siftup(array, 13);
    print_array(array);
	std::vector<int> array2 = {-1, 18, 20, 15, 29, 23, 17, 22, 35, 40, 51, 19};
	print_array(array2);
    siftdown(array2);
    print_array(array2);
    return 0;
}