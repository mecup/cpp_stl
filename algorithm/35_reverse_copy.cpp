/**
* reverse_copy() 算法可以将源序列复制到目的序列中，目的序列中的元素是逆序的。定义源序列的前两个迭代器参数必须是双向迭代器。目的序列由第三个参数指定，它是目的序列的开始迭代器
* 这个算法会返回一个输出迭代器，它指向目的序列最后一个元素的下一个位置
* 
* 如果是要原地逆序，可以使用reverse() 
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
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; 
	vector<int> v2(20);
	printVector(v);
	auto it = reverse_copy(v.begin(), v.end(), v2.begin());
	printVector(v2);
	cout << "reverse_copy返回的迭代器位置：" << it-v2.begin() << endl << endl;
	
	cout << "------------- 原地逆序 -------------" << endl;
	reverse(v.begin(), v.end());
	printVector(v);
	return 0;
}
