/**
* 在序列 A 中查找序列 B 最后一次出现的位置(也可以自定义规则)
* find_end() 函数会返回一个正向迭代器，当函数查找成功时，该迭代器指向查找到的子序列中的第一个元素；反之，如果查找失败，则该迭代器的指向序列A的end()
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
	/******************* 默认的find_end（判断相等） **********************/
	vector<int> v1 = {1, 2, 3, 4, 8, 12, 18, 1, 2, 3};
	vector<int> v2 = { 1, 2, 3 };
	auto it = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (it != v1.end())
		cout << "最后一个{1,2,3}的起始位置为：" << it - v1.begin() << ", *it = " << *it << endl;
	else 
		cout << "没有找到符合条件的子序列" << endl;	
	
	/******************* 自定义规则的find_end **********************/
	vector<int> v3 = {8, 6, 14, 12, 40, 34, 8, 12, 28, 33, 39};
	vector<int> v4 = { 2, 4, 6 };
	auto it2 = find_end(v3.begin(), v3.end(), v4.begin(), v4.end(), cmp);
	if (it2 != v3.end())
		cout << "最后一个能分别被 {2、4、6} 整除中的子序列位置：" << it2 - v3.begin() << ", *it2 = " << *it2 << endl;
	else 
		cout << "没有找到符合条件的子序列" << endl;
	cout << endl;
	return 0;
}
