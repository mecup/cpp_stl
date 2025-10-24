/**
* 有些场景中，我们需要将 2 个有序序列合并为 1 个有序序列，这时就可以借助 merge() 或者 inplace_merge() 函数实现。
* merge() 函数用于将 2 个有序序列合并为 1 个有序序列，前提是这 2 个有序序列的排序规则相同（要么都是升序，要么都是降序）。并且得到的新有序序列的排序规则也和这 2 个有序序列相同。
* merge() 函数会返回一个输出迭代器，其指向的是新有序序列中最后一个元素之后的位置
* 
* 当 2 个有序序列存储在同一个数组或容器中时，如果想将它们合并为 1 个有序序列，除了使用 merge() 函数，更推荐使用 inplace_merge() 函数。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	/******************* merge **********************/
	vector<int> result(100); //开辟一个足够大的vector，用来存储合并后的结果
	int a1[] = {1, 7, 11, 15, 35};
	int a2[] = {3, 8, 12, 28, 33, 39};
 	auto resultEnd = merge(a1, a1+5, a2, a2+6, result.begin()); //如果两个数组是从大到小的顺序呢？该怎么合并？
	cout << "使用merge合并后的新数组：" << endl;
	for (auto it = result.begin(); it != result.end(); it++) //想想看，为什么会输出这么多0？如果换成it != resultEnd呢？
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "合并后的新数组中实际上有" << resultEnd - result.begin() << "个元素" << endl << endl;
	
	/******************* inplace_merge **********************/
	int a[] = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	inplace_merge(a, a+5, a+11);
	cout << "使用inplace_merge合并后的新数组：" << endl;
	for (int aa : a)
	{
		cout << aa << " ";
	}
	cout << endl;
	return 0;
}
