/**
* adjacent_find() 函数用于在指定范围内查找 2 个连续相等的元素
* 该函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向的是连续相等元素的第 1 个元素；而如果查找失败，该迭代器的指向end
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //如果两个数字的个位数相同，则返回true，否则返回false
{
	if (n1%10==n2%10) 
		return true;
	return false;
}

int main()
{
	/******************* 默认规则 **********************/
	vector<int> v = {19, 7, 11, 15, 35, 35, 8, 12, 28, 33, 39};
	auto it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
		cout << "连续相等的第一个元素：" << *it << endl;
	else 
		cout << "没有找到（默认规则）" << endl;
	cout << endl;
	
	/******************* 自定义规则 **********************/
	it = adjacent_find(v.begin(), v.end(), cmp);
	if (it != v.end())
		cout << "符合自定义规则的连续第一个元素：" << *it << endl;
	else 
		cout << "没有找到（自定义规则）" << endl;
	cout << endl;
	return 0;
}
