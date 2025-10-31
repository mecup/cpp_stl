/**
* binary_search() ���������ڲ���ָ���������Ƿ����ĳ��Ŀ��Ԫ�ء�
* �ú����᷵��һ�� bool ����ֵ����� binary_search() ������ [first, last) �����ڳɹ��ҵ��� val ��ȵ�Ԫ�أ��򷵻� true����֮�򷵻� false��
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
	int num1 = 4; //Ҫ���ҵ�Ԫ��
	int num2 = 6; //Ҫ���ҵ�Ԫ��
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 5, 9, 10, 21, 40, 60, 80}; 
	bool isExist = binary_search(v.begin(), v.end(), num1);
	cout << "�Ƿ����" << num1 << "���Ԫ�أ�" << (isExist?"��":"��") << endl;
	isExist = binary_search(v.begin(), v.end(), num2);
	cout << "�Ƿ����" << num2 << "���Ԫ�أ�" << (isExist?"��":"��") << endl;
	return 0;
}
