/**
* ��������һ���龳����һ������ 100 ���Ԫ�ص�������������ֻ�������ȡ��ֵ��С�� 10 ��Ԫ�أ������ʵ���أ�
* ͨ��ǰ���ѧϰ�����߿��ܻ��뵽ʹ�� sort() ���� stable_sort() ����������ͨ���������д洢�� 100 ���Ԫ�ؽ������򣬾Ϳ��Գɹ�ɸѡ����С�� 10 ��Ԫ�ء�
* ������Ϊ����ȡ 10 ��Ԫ�أ�ȴҪ�ȶ� 100 ���Ԫ�ؽ������򣬿����֪����ʵ�ַ�ʽ��Ч���Ƿǳ��͵ġ�
* ���ڽ�����Ƶ����⣬C++ STL ��׼���ṩ�˸���Ч�Ľ����������ʹ�� partial_sort() ���� partial_sort_copy() ����
* 
* partial_sort() ����ֻ������ array��vector��deque �� 3 ������
* 
* partial_sort_copy() �����Ĺ��ܺ� partial_sort() ���ƣ�Ψһ���������ڣ�ǰ�߲����ԭ���������κα䶯�������Ƚ�ѡ���Ĳ���Ԫ�ؿ���������ָ��������������У�Ȼ���ٶ��ⲿ��Ԫ�ؽ�������
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct student
{
	string name; //����
	int score; //����
};
bool cmp(student stu1, student stu2)
{
	return stu1.score > stu2.score;
}

int main()
{
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	cout << "�����ʼ���У�";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** partial_sort �ҵ���С��3���� *****************/
	partial_sort(v.begin(), v.begin()+3, v.end());
	cout << "partial_sort �ҵ���С��3������";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** partial_sort_copy �ҵ�����3���������ŵ�result�� *****************/
	vector<int> result;
	//vector<int> result(3);
	//result.reserve(3);
	result.resize(3);
	partial_sort_copy(v.begin(), v.end(), result.begin(), result.begin()+3, greater<int>());
	cout << "partial_sort_copy �ҵ�����3���������ŵ�����һ��vector�У�";
	for (auto it = result.begin(); it != result.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
