/**
* 排序操作是比较耗费时间的，尤其当数据量很大的时候。因此在设计程序时，我们应该有意识的去避免执行一些不必要的排序操作。
* 那么，怎样才能判断一个序列是否为有序序列呢？很简单，使用 is_sorted() 函数即可，此函数专门用于判断某个序列是否为有序序列。
* 
* 和 is_sorted() 函数相比，is_sorted_until() 函数不仅能检测出某个序列是否有序，还会返回一个正向迭代器，该迭代器指向的是当前序列中第一个破坏有序状态的元素。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	bool ok = false;
	//原始数组
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	ok = is_sorted(v.begin(), v.end());
	cout << "原始数组是否排序：" << (ok?"是":"否") << endl;
	
	/****************** is_sorted *********************/
	//将数组按照默认规则进行排序（从小到大）
	sort(v.begin(), v.end());
	
	ok = is_sorted(v.begin(), v.end()); //按照默认规则判断是否排序
	cout << "【第1次】数组是否按照规则排序：" << (ok?"是":"否") << endl;
	
	ok = is_sorted(v.begin(), v.end(), greater<int>());//按照从大到小判断是否排序
	cout << "【第2次】数组是否按照规则排序：" << (ok?"是":"否") << endl;
	
	/****************** is_sorted_until *********************/
	vector<int> v2 = {100, 99, 98, 92, 85, 87, 12, 51, 6, 10, 88};
	auto it = is_sorted_until(v2.begin(), v2.end(), greater<int>());
	if (it == v2.end())
		cout << "is_sorted_until测试：数组有序" << endl;
	else 
		cout << "is_sorted_until测试：数组无序，第一个破坏有序性的元素是" << *it << endl;
	
	return 0;
}
