/**
* binary_search() 函数，用于查找指定区域内是否包含某个目标元素。
* 该函数会返回一个 bool 类型值，如果 binary_search() 函数在 [first, last) 区域内成功找到和 val 相等的元素，则返回 true；反之则返回 false。
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
	int num1 = 4; //要查找的元素
	int num2 = 6; //要查找的元素
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	bool isExist = binary_search(v.begin(), v.end(), num1);
	cout << "是否存在" << num1 << "这个元素：" << (isExist?"是":"否") << endl;
	isExist = binary_search(v.begin(), v.end(), num2);
	cout << "是否存在" << num2 << "这个元素：" << (isExist?"是":"否") << endl;
	return 0;
}
