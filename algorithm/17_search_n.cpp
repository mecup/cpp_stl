/**
* �� search() һ����search_n() ����Ҳ������ָ�������ڲ��ҵ�һ������Ҫ��������С�
* ��֮ͬ�����ڣ�ǰ�߲��ҵ��������пɰ��������ͬ��Ԫ�أ������߲��ҵ�ֻ���ǰ��������ͬԪ�ص������С�
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(int n1, int n2) //���n1������n2���򷵻�true�����򷵻�false
{
	if (n1%n2==0)  //�����n2��ʵ������search_n�ĵ�4��������STL�Ὣ��4����������n2
		return true;
	return false;
}

int main()
{
	/******************* Ĭ�Ϲ��� **********************/
	vector<int> v1 = {1, 2, 3, 4, 4, 4, 18, 1, 2, 3};
	auto it = search_n(v1.begin(), v1.end(), 3, 4);
	if (it != v1.end())
		cout << "��һ������3��4��λ��Ϊ��" << it - v1.begin() << ", *it = " << *it << endl;
	else 
		cout << "û���ҵ�����������������" << endl;	
	
	/******************* �Զ������ **********************/
	vector<int> v2 = {8, 64, 24, 12, 40, 34, 55, 66, 77, 47, 67};
	auto it2 = search_n(v2.begin(), v2.end(), 3, 11, cmp); //����3��������Ԫ�أ�����ÿһ����������11
	if (it2 != v2.end())
		cout << "��һ������3��������11������λ��Ϊ��" << it2 - v2.begin() << ", *it2 = " << *it2 << endl;
	else 
		cout << "û���ҵ�����������������" << endl;
	cout << endl;
	return 0;
}
