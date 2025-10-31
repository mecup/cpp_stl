/**
* lower_bound() 函数用于在指定区域内查找不小于目标值的第一个元素，该函数仅适用于已排好序的序列
* 返回指向下界位置的迭代器
* 
* 注意：这里所说的“已排好序”，并不要求数据完全按照某个排序规则进行升序或降序排序。
* 而仅仅要求 [first, last) 区域内所有令 element<val（或者 comp(val, element）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 9, 8, 7, 6}; 
	auto bound = lower_bound(v.begin(), v.end(), 4);
	cout << "元素4的下界位置：" << bound - v.begin();
	cout << endl;
	
	vector<int> v2 = {90, 100, 90, 80, 80, 80, 80, 40, 50, 9, 10, 9, 8, 7, 6}; 
	bound = lower_bound(v2.begin(), v2.end(), 80, greater<int>());
	cout << "元素80的下界位置：" << bound - v2.begin();
	cout << endl;
	return 0;
}
