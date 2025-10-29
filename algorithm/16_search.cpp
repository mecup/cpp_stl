/**
* find_end() 函数用于在序列 A 中查找序列 B 最后一次出现的位置。那么，如果想知道序列 B 在序列 A 中第一次出现的位置，该如何实现呢？可以借助 search() 函数。
* search() 函数的功能恰好和 find_end() 函数相反，用于在序列 A 中查找序列 B 第一次出现的位置
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //如果n1能将n2整除，则返回true，否则返回false
{
	if (n1%n2==0) 
		return true;
	return false;
}

int main()
{
	/******************* 默认规则 **********************/
	vector<int> v1 = {1, 2, 3, 4, 8, 12, 18, 1, 2, 3};
	vector<int> v2 = { 1, 2, 3 };
	auto it = search(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (it != v1.end())
		cout << "第一个{1,2,3}的起始位置为：" << it - v1.begin() << ", *it = " << *it << endl;
	else 
		cout << "没有找到符合条件的子序列" << endl;	
	
	/******************* 自定义规则 **********************/
	vector<int> v3 = {8, 64, 24, 12, 40, 34, 8, 12, 22, 44, 66};
	vector<int> v4 = { 2, 4, 6 };
	auto it2 = search(v3.begin(), v3.end(), v4.begin(), v4.end(), cmp);
	if (it2 != v3.end())
		cout << "第一个能分别被 {2、4、6} 整除中的子序列位置：" << it2 - v3.begin() << ", *it2 = " << *it2 << endl;
	else 
		cout << "没有找到符合条件的子序列" << endl;
	cout << endl;
	return 0;
}
