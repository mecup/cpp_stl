/**
* rotate_copy() 算法会在新序列中生成一个序列的旋转副本，并保持原序列不变。rotate_copy() 的前 3 个参数和 copy() 是相同的；第 4 个参数是一个输出迭代器，它指向目的序列的第一个元素。
* 这个算法会返回一个目的序列的输出迭代器，它指向最后一个被复制元素的下一个位置。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//打印vector的内容
void printVector(vector<int> v)
{
	for(auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; 
	vector<int> v2(v.size());  //将旋转后的结果复制到这里
	cout << "========== 原始vector ===========" << endl;
	printVector(v);
	cout << endl;
	cout << "========== 旋转复制后的结果 ===========" << endl;
	auto it = rotate_copy(v.begin(), v.begin() + 2, v.end(), v2.begin());
	printVector(v2);
	cout << "复制后目标容器中最后一个被复制元素的下一个位置：" << it-v2.begin() << endl << endl;
	return 0;
}
