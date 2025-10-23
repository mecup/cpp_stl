/**
* ��������ǱȽϺķ�ʱ��ģ����䵱�������ܴ��ʱ���������Ƴ���ʱ������Ӧ������ʶ��ȥ����ִ��һЩ����Ҫ�����������
* ��ô�����������ж�һ�������Ƿ�Ϊ���������أ��ܼ򵥣�ʹ�� is_sorted() �������ɣ��˺���ר�������ж�ĳ�������Ƿ�Ϊ�������С�
* 
* �� is_sorted() ������ȣ�is_sorted_until() ���������ܼ���ĳ�������Ƿ����򣬻��᷵��һ��������������õ�����ָ����ǵ�ǰ�����е�һ���ƻ�����״̬��Ԫ�ء�
**/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	bool ok = false;
	//ԭʼ����
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	ok = is_sorted(v.begin(), v.end());
	cout << "ԭʼ�����Ƿ�����" << (ok?"��":"��") << endl;
	
	/****************** is_sorted *********************/
	//�����鰴��Ĭ�Ϲ���������򣨴�С����
	sort(v.begin(), v.end());
	
	ok = is_sorted(v.begin(), v.end()); //����Ĭ�Ϲ����ж��Ƿ�����
	cout << "����1�Ρ������Ƿ��չ�������" << (ok?"��":"��") << endl;
	
	ok = is_sorted(v.begin(), v.end(), greater<int>());//���մӴ�С�ж��Ƿ�����
	cout << "����2�Ρ������Ƿ��չ�������" << (ok?"��":"��") << endl;
	
	/****************** is_sorted_until *********************/
	vector<int> v2 = {100, 99, 98, 92, 85, 87, 12, 51, 6, 10, 88};
	auto it = is_sorted_until(v2.begin(), v2.end(), greater<int>());
	if (it == v2.end())
		cout << "is_sorted_until���ԣ���������" << endl;
	else 
		cout << "is_sorted_until���ԣ��������򣬵�һ���ƻ������Ե�Ԫ����" << *it << endl;
	
	return 0;
}
