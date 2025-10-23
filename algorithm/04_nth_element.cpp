/**
* 当采用默认的升序排序规则（std::less<T>）时，该函数可以从某个序列中找到第 n 小的元素 K，并将 K 移动到序列中第 n 的位置处。
* 不仅如此，整个序列经过 nth_element() 函数处理后，所有位于 K 之前的元素都比 K 小，所有位于 K 之后的元素都比 K 大。
* 我们也可以将 nth_element() 函数的排序规则自定义为降序排序，此时该函数会找到第 n 大的元素 K 并将其移动到第 n 的位置处，同时所有位于 K 之前的元素都比 K 大，所有位于 K 之后的元素都比 K 小。
* 
* nth_element() 函数只适用于 array、vector、deque 这 3 个容器
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student
{
	string name; //姓名
	int score; //分数
};
bool cmp(student stu1, student stu2)
{
	return stu1.score > stu2.score;
}

int main()
{
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	sort(v.begin(), v.end());
	cout << "数组从大到小的排列：";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** 找到第3小的数 *****************/
	//nth_element函数会将你指定的第 nth个位置的元素放到它排序后应该在的位置，如果是第3小的数，那么会被放在[2]的位置上。
	nth_element(v.begin(), v.begin()+2, v.end());
	cout << "找到第3小的数之后的数组排列：";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "第3小的数：" << v.at(2);
	cout << endl;
	
	/*************** 找到第3大的数 *****************/
	//第3大的数，那么会被放在[2]的位置上
	nth_element(v.begin(), v.begin()+2, v.end(), greater<int>());
	cout << "找到第3大的数之后的数组排列：";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "第3大的数：" << v.at(2);
	cout << endl;
}
