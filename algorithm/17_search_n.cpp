/**
* 和 search() 一样，search_n() 函数也用于在指定区域内查找第一个符合要求的子序列。
* 不同之处在于，前者查找的子序列中可包含多个不同的元素，而后者查找的只能是包含多个相同元素的子序列。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //如果n1能整除n2，则返回true，否则返回false
{
	if (n1%n2==0)  //这里的n2，实际上是search_n的第4个参数，STL会将第4个参数传入n2
		return true;
	return false;
}

int main()
{
	/******************* 默认规则 **********************/
	vector<int> v1 = {1, 2, 3, 4, 4, 4, 18, 1, 2, 3};
	auto it = search_n(v1.begin(), v1.end(), 3, 4);
	if (it != v1.end())
		cout << "第一处连续3个4的位置为：" << it - v1.begin() << ", *it = " << *it << endl;
	else 
		cout << "没有找到符合条件的子序列" << endl;	
	
	/******************* 自定义规则 **********************/
	vector<int> v2 = {8, 64, 24, 12, 40, 34, 55, 66, 77, 47, 67};
	auto it2 = search_n(v2.begin(), v2.end(), 3, 11, cmp); //查找3个连续的元素，它们每一个都能整除11
	if (it2 != v2.end())
		cout << "第一处连续3个能整除11的数的位置为：" << it2 - v2.begin() << ", *it2 = " << *it2 << endl;
	else 
		cout << "没有找到符合条件的子序列" << endl;
	cout << endl;
	return 0;
}
