/**
* ��Щ�����У�������Ҫ�� 2 ���������кϲ�Ϊ 1 ���������У���ʱ�Ϳ��Խ��� merge() ���� inplace_merge() ����ʵ�֡�
* merge() �������ڽ� 2 ���������кϲ�Ϊ 1 ���������У�ǰ������ 2 ���������е����������ͬ��Ҫô��������Ҫô���ǽ��򣩡����ҵõ������������е��������Ҳ���� 2 ������������ͬ��
* merge() �����᷵��һ���������������ָ��������������������һ��Ԫ��֮���λ��
* 
* �� 2 ���������д洢��ͬһ�������������ʱ������뽫���Ǻϲ�Ϊ 1 ���������У�����ʹ�� merge() ���������Ƽ�ʹ�� inplace_merge() ������
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	/******************* merge **********************/
	vector<int> result(100); //����һ���㹻���vector�������洢�ϲ���Ľ��
	int a1[] = {1, 7, 11, 15, 35};
	int a2[] = {3, 8, 12, 28, 33, 39};
 	auto resultEnd = merge(a1, a1+5, a2, a2+6, result.begin()); //������������ǴӴ�С��˳���أ�����ô�ϲ���
	cout << "ʹ��merge�ϲ���������飺" << endl;
	for (auto it = result.begin(); it != result.end(); it++) //���뿴��Ϊʲô�������ô��0���������it != resultEnd�أ�
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "�ϲ������������ʵ������" << resultEnd - result.begin() << "��Ԫ��" << endl << endl;
	
	/******************* inplace_merge **********************/
	int a[] = {1, 7, 11, 15, 35, 3, 8, 12, 28, 33, 39};
	inplace_merge(a, a+5, a+11);
	cout << "ʹ��inplace_merge�ϲ���������飺" << endl;
	for (int aa : a)
	{
		cout << aa << " ";
	}
	cout << endl;
	return 0;
}
