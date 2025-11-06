/**
* std::swap_ranges用于交换两个序列中指定范围内的元素。
* 它需要三个迭代器参数：第一个序列的起止迭代器，以及第二个序列的起始迭代器。它会逐个交换对应位置上的元素，因此时间复杂度是线性的O(N)
* 
* 当需要交换两个完整容器的所有内容时，优先使用 std::swap。特别是对于STL容器，它的效率极高（O(1)）
* 当只需要交换容器或数组中的一部分元素，或者需要在两个不同类别的容器（如 vector和 deque）之间交换元素时，使用 std::swap_ranges
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//打印vector的内容
void printVector(vector<int> vs)
{
	for(auto it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 5}; 
	vector<int> v2 = {100, 200, 300, 400, 500}; 
	
	swap_ranges(v1.begin(), v1.begin() + 3, v2.begin());
	
	cout << "========== swap_ranges后的结果 ===========" << endl;
	printVector(v1);
	printVector(v2);
	return 0;
}
