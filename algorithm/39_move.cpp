/**
* move() 算法会将它的前两个输入迭代器参数指定的序列移到第三个参数定义的目的序列的开始位置，第三个参数必须是输出迭代器。
* 这个算法返回的迭代器指向最后一个被移动到目的序列的元素的下一个位置。
* 
* std::move算法（定义在 <algorithm>头文件中）的核心价值在于：
* 当处理支持移动语义的类型（如 std::string、std::vector或自定义包含资源的类）时，它可以通过转移资源所有权而非复制数据来显著提升性能。
* 
* 对基本类型无效：int、double等简单类型没有动态资源，移动与拷贝开销相同，使用 std::move无性能收益。
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//打印vector的内容
void printVector(vector<string> vs)
{
	for(auto it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	vector<string> vs = {"hello", "world", "you", "are", "good"}; 
	vector<string> result(vs.size());  
	printVector(vs);
	cout << endl;
	cout << "========== move后的结果 ===========" << endl;
	auto it = move(vs.begin(), vs.end(), result.begin());
	printVector(result);
	cout << "result的end位置：" << it - result.begin() << endl;
	return 0;
}
