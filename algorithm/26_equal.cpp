/**
* 如果两个序列的长度相同，并且对应元素都相等，equal() 算法会返回 true
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	vector<int> v2 = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	bool ok = equal(v1.begin(), v1.end(), v2.begin(), v2.end());
	cout << (ok?"v1 与 v2 内容完全相同" : "v1 与 v2 内容不相同") << endl;
	return 0;
}
