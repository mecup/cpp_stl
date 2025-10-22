/**
* 1��sort() ֻ�� array��vector��deque �� 3 �������ṩ֧��
* 2������ָ��������ֵ��ȵ�Ԫ�أ�sort() �����޷���֤���ǵ����λ�ò������ı�
* 3�������Ҫ���������Ҫ��֤���Ԫ�ص����λ�ã�����ʹ�� stable_sort() ����������ʹ�÷����� sort() ��ͬ
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
	/*************** �ַ����������� *****************/
	vector<string> vs = {"china", "usa", "japan", "germany", "france", "england", "india"};
	sort(vs.begin(), vs.end());
	cout << "�ַ����������У�";
	for (auto it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
		
	/*************** ���ֽ������� *****************/
	vector<int> v = {56, 33, 98, 26, 43, 100, 12, 51, 6, 10, 88};
	sort(v.begin(), v.end(), greater<int>());
	cout << "���ֽ������У�";
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	/*************** �ṹ���Զ������� *****************/
	vector<student> stus;
	student s1 = {"����", 89};
	student s2 = {"����", 92};
	student s3 = {"��������", 77};
	student s4 = {"����", 86};
	student s5 = {"����", 90};
	student s6 = {"����", 96};
	stus.push_back(s1);
	stus.push_back(s2);
	stus.push_back(s3);
	stus.push_back(s4);
	stus.push_back(s5);
	stus.push_back(s6);
	sort(stus.begin(), stus.end(), cmp);
	cout << "ѧ������������" << endl;
	for (auto it = stus.begin(); it != stus.end(); it++)
	{
		cout << it->name << " " << it->score << endl;
	}
}
