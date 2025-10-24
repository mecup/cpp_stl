/**
* find() 函数用于在指定范围内查找和目标元素值相等的第一个元素。
* 该函数会返回一个输入迭代器，当 find() 函数查找成功时，其指向的是在 [first, last) 区域内查找到的第一个目标元素；如果查找失败，则该迭代器的指向和 last 相同。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	/******************* 在vector中find **********************/
	vector<int> v = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	auto it = find(v.begin(), v.end(), 15);
	if (it != v.end())
		cout << "在vector中find：" << *it << endl;
	else 
		cout << "在vector中find没有找到" << endl;
	cout << endl;
	
	/******************* 在数组中find **********************/
	int a[] = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	int *pos = find(a, a+11, 15);
	cout << "在数组中find：" << *pos << endl;
	cout << endl;
	return 0;
}
