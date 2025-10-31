/**
* equel_range() �����Ĺ�����ȫ���Կ����� lower_bound() �� upper_bound() �����ĺ���
* ������һ��pair��ͬʱ����Ҫ����Ԫ���������е��Ͻ���½�λ�õĵ�����
* 
* ע�⣺�ú����������ڡ����ź��򡱵����С���ν�����ź��򡱣�������Ҫ�� [first, last) �����ڵ������ϸ���ĳ�����������������������
* ֻҪ���㡰������ element<val������ comp(val, element��������Ԫ�ض�λ�ڲ�����Ԫ�ص�ǰ�棨���� element Ϊָ����Χ�ڵ�Ԫ�أ������ɡ�
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	auto bound = equal_range(v.begin(), v.end(), 4);
	cout << "Ԫ��4���Ͻ�λ�ã�" << bound.first - v.begin() << "���½�λ�ã�" << bound.second - v.begin();
	cout << endl;
	return 0;
}
