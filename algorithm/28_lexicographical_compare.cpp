/**
* lexicographical_compare比较两个序列的字典序排列大小
* 如果第一个序列的字典序小于第二个，这个算法会返回 true，否则返回 false
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 4, 4, 5, 5, 9, 10, 21, 40, 60, 80}; 
	vector<int> v2 = {1, 2, 3, 4, 4, 5, 5, 5, 9, 10, 21, 40, 60, 80}; 
	bool ret = lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
	cout << "比较结果：" << (ret?"true":"false") << endl;
	
	vector<string> s1 = {"the", "cat", "is", "red"};
	vector<string> s2 = {"the", "dog", "is", "yellow"};
	ret = lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	cout << "比较结果：" << (ret?"true":"false") << endl;
	return 0;
}
