/**
* find_if() 函数用于查找符合谓词函数规则的第一个元素，而 find_if_not() 函数则用于查找第一个不符合谓词函数规则的元素。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n) //如果是偶数则返回true，否则返回false
{
	if (n%2==0) 
		return true;
	return false;
}

int main()
{
	/******************* find_if **********************/
	vector<int> v = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	auto it = find_if(v.begin(), v.end(), cmp);
	if (it != v.end())
		cout << "vector中第一个偶数为：" << *it << endl;
	else 
		cout << "find_if没有找到偶数" << endl;
	cout << endl;
	
	/******************* find_if_not **********************/
	int a[] = {8, 6, 14, 12, 40, 34, 8, 12, 28, 33, 39};
	v = vector<int>(a, a+11); //数组转vector
	auto it2 = find_if_not(v.begin(), v.end(), cmp);
	if (it2 != v.end())
		cout << "vector中第一个不是偶数的数字为：" << *it2 << endl;
	else 
		cout << "find_if没有找到非偶数" << endl;
	cout << endl;
	return 0;
}
