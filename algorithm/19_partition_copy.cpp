/**
* 在某些场景中，我们需要类似 partition() 或者 stable_partition() 函数“分组”的功能，但并不想对原序列做任何修改。这种情况下，就可以考虑使用 partition_copy() 函数。
* partition_copy() 函数也能按照某个筛选规则对指定区域内的数据进行“分组”，并且分组后不会改变各个元素的相对位置。
* 更重要的是，partition_copy() 函数不会对原序列进行本地重新排列，而是以复制的方式将序列中各个数据“分组”到其它的指定位置存储。
* 
* partition_copy() 函数返回一个 pair 类型值，其包含 2 个迭代器，第一个迭代器指向的是第一个分组最后一个元素之后的位置；第二个迭代器指向的是第二个分组最后一个元素之后的位置
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
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	vector<int> oushu(10); //存储偶数
	vector<int> jishu(10); //存储奇数
	/******************* partition_copy **********************/
	auto result = partition_copy(v.begin(), v.end(), oushu.begin(), jishu.begin(), cmp);
	cout << "偶数部分：";
	for (auto it = oushu.begin(); it != result.first; it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "非偶数部分：";
	for (auto it = jishu.begin(); it != result.second; it++) //注意观察打印范围从哪里到哪里
	{
		cout << *it << " ";
	}
	cout << endl;
}
