/**
* find_first_of() 函数在 A 序列中查找和 B 序列中任意元素相匹配的第一个元素
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //如果n1能整除n2则返回true，否则返回false
{
	if (n1%n2==0) 
		return true;
	return false;
}

int main()
{
	/******************* 默认规则的find_first_of **********************/
	vector<int> v1 = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	vector<int> v2 = {14, 15, 16};
	auto it = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (it != v1.end())
		cout << "v1元素中第一个与v2元素相同的：" << *it << endl;
	else 
		cout << "find_first_of在v1中没有找到符合条件的元素" << endl;
	cout << endl;
	
	/******************* 自定义规则的find_first_of **********************/
	vector<int> v3 = {8, 6, 14, 12, 40, 34, 8, 12, 28, 33, 39};
	vector<int> v4 = {11, 13};
	auto it2 = find_first_of(v3.begin(), v3.end(), v4.begin(), v4.end(), cmp);
	if (it2 != v3.end())
		cout << "v3元素中第一个是v4元素整数倍的：" << *it2 << endl;
	else 
		cout << "find_first_of在v3中没有找到符合条件的元素" << endl;
	cout << endl;
	return 0;
}
