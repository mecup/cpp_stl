/**
* equel_range() 函数的功能完全可以看做是 lower_bound() 和 upper_bound() 函数的合体
* 它返回一个pair，同时返回要查找元素在容器中的上界和下界位置的迭代器
* 
* 注意：该函数仅适用于“已排好序”的序列。所谓“已排好序”，并不是要求 [first, last) 区域内的数据严格按照某个排序规则进行升序或降序排序
* 只要满足“所有令 element<val（或者 comp(val, element）成立的元素都位于不成立元素的前面（其中 element 为指定范围内的元素）”即可。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	auto bound = equal_range(v.begin(), v.end(), 4);
	cout << "元素4的上界位置：" << bound.first - v.begin() << "，下界位置：" << bound.second - v.begin();
	cout << endl;
	return 0;
}
