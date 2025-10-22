/**
* 假设这样一种情境，有一个存有 100 万个元素的容器，但我们只想从中提取出值最小的 10 个元素，该如何实现呢？
* 通过前面的学习，读者可能会想到使用 sort() 或者 stable_sort() 排序函数，即通过对容器中存储的 100 万个元素进行排序，就可以成功筛选出最小的 10 个元素。
* 但仅仅为了提取 10 个元素，却要先对 100 万个元素进行排序，可想而知这种实现方式的效率是非常低的。
* 对于解决类似的问题，C++ STL 标准库提供了更高效的解决方案，即使用 partial_sort() 或者 partial_sort_copy() 函数
* 
* partial_sort() 函数只适用于 array、vector、deque 这 3 个容器
* 
* partial_sort_copy() 函数的功能和 partial_sort() 类似，唯一的区别在于，前者不会对原有数据做任何变动，而是先将选定的部分元素拷贝到另外指定的数组或容器中，然后再对这部分元素进行排序。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student
{
	string name; //姓名
	int score; //分数
};
bool cmp(student stu1, student stu2)
{
	return stu1.score > stu2.score;
}

int main()
{
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	cout << "数组初始排列：";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** partial_sort 找到最小的3个数 *****************/
	partial_sort(v.begin(), v.begin()+3, v.end());
	cout << "partial_sort 找到最小的3个数：";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** partial_sort_copy 找到最大的3个数，并放到result中 *****************/
	vector<int> result;
	//vector<int> result(3);
	//result.reserve(3);
	result.resize(3);
	partial_sort_copy(v.begin(), v.end(), result.begin(), result.begin()+3, greater<int>());
	cout << "partial_sort_copy 找到最大的3个数，并放到另外一个vector中：";
	for (auto it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
