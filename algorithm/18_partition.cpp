/**
* partition 可直译为“分组”，partition() 函数可根据用户自定义的筛选规则，重新排列指定区域内存储的数据，使其分为 2 组，第一组为符合筛选条件的数据，另一组为不符合筛选条件的数据。
* partition() 函数会返回一个迭代器，其指向的是两部分数据的分界位置，更确切地说，指向的是第二组数据中的第 1 个元素。
* stable_partition() 函数可以保证对指定区域内数据完成分组的同时，不改变各组内元素的相对位置。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n) //如果是偶数返回true，否则返回false
{
	return n%2==0;
}

int main()
{
	/******************* partition **********************/
	vector<int> v1 = {1, 9, 4, 9, 0, 3, 0, 3};
	auto mid = partition(v1.begin(), v1.end(), cmp);
	cout << "[partition]偶数部分：";
	for (auto it = v1.begin(); it != mid; it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "[partition]非偶数部分：";
	for (auto it = mid; it != v1.end(); it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/******************* stable_partition **********************/
	vector<int> v2 = {1, 9, 4, 9, 0, 3, 0, 3};
	mid = stable_partition(v2.begin(), v2.end(), cmp);
	cout << "[stable_partition]偶数部分：";
	for (auto it = v2.begin(); it != mid; it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "[stable_partition]非偶数部分：";
	for (auto it = mid; it != v2.end(); it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
}
