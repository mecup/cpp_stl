/**
* 对于如何在已分好组的数据中找到分界位置，C++ 11标准库提供了专门解决此问题的函数，即 partition_point() 函数。
* 该函数会返回一个正向迭代器，该迭代器指向的是 [first, last] 范围内第一个不符合 cmp 筛选规则的元素。
* 与find_if_not的差异
1. 前提条件：最关键的区别
find_if_not() 对输入序列没有任何前提要求。它从 first开始逐个检查元素，直到找到第一个不满足谓词条件的元素。就像你在一份未分类的名单中，从头开始找第一个不是程序员的人。
partition_point() 则要求序列??已经是一个分区序列。这意味着序列中所有满足谓词条件的元素都必须排在所有不满足条件的元素之前。
它利用这个特性进行高效查找。好比一份名单已经按“是程序员”和“不是程序员”分成了前后两部分，partition_point()的任务是快速找到这两部分之间的那条分界线。
2. 性能：线性扫描 vs. 二分查找
由于 find_if_not()不知道序列的状态，它只能采用线性扫描，最坏情况下需要检查所有元素。
partition_point()知道序列是分区的，因此可以采用二分查找，效率高很多，尤其对于大型数据集。
3. 返回值：查找结果 vs. 分区边界
find_if_not() 返回的是第一个“不满足条件”的元素的迭代器。这直接是查找的结果。
partition_point() 返回的是“第二个分区”的起始迭代器。它指向的是第一个“不满足条件”的元素，但这个返回值还有一个含义是作为分区的标志点。你可以利用这个点将序列明确分成两个子范围。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n) //如果是奇数返回true，否则返回false
{
	return n%2==1;
}

int main()
{
	vector<int> v = {1, 21, 3, 41, 5, 61, 7, 81, 9, 101, 2, 4, 6, 8}; 
	/******************* partition_point **********************/
	auto point = partition_point(v.begin(), v.end(), cmp);
	cout << "奇数部分：";
	for (auto it = v.begin(); it != point; it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "非奇数部分：";
	for (auto it = point; it != v.end(); it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
}
