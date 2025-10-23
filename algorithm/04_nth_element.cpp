/**
* ������Ĭ�ϵ������������std::less<T>��ʱ���ú������Դ�ĳ���������ҵ��� n С��Ԫ�� K������ K �ƶ��������е� n ��λ�ô���
* ������ˣ��������о��� nth_element() �������������λ�� K ֮ǰ��Ԫ�ض��� K С������λ�� K ֮���Ԫ�ض��� K ��
* ����Ҳ���Խ� nth_element() ��������������Զ���Ϊ�������򣬴�ʱ�ú������ҵ��� n ���Ԫ�� K �������ƶ����� n ��λ�ô���ͬʱ����λ�� K ֮ǰ��Ԫ�ض��� K ������λ�� K ֮���Ԫ�ض��� K С��
* 
* nth_element() ����ֻ������ array��vector��deque �� 3 ������
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
	sort(v.begin(), v.end());
	cout << "����Ӵ�С�����У�";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** �ҵ���3С���� *****************/
	//nth_element�����Ὣ��ָ���ĵ� nth��λ�õ�Ԫ�طŵ��������Ӧ���ڵ�λ�ã�����ǵ�3С��������ô�ᱻ����[2]��λ���ϡ�
	nth_element(v.begin(), v.begin()+2, v.end());
	cout << "�ҵ���3С����֮����������У�";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "��3С������" << v.at(2);
	cout << endl;
	
	/*************** �ҵ���3����� *****************/
	//��3���������ô�ᱻ����[2]��λ����
	nth_element(v.begin(), v.begin()+2, v.end(), greater<int>());
	cout << "�ҵ���3�����֮����������У�";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "��3�������" << v.at(2);
	cout << endl;
}
