#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");


	// ����� ������ ���� �������� ����������������� ���������� ���� �������
	
	/*cout << "�������� ��� �������� �� ������ �������� a � b" << endl;
	vector<int> b = { 1, 111, 2, 222, 2, 111, 3, 222 };
	vector<int> a = { 1, 111, 2, 222, 3, 333 };
	cout << " 2 = { 1, 111, 2, 222, 2, 111, 3, 222 }" << endl;
	cout << "1 = { 1, 111, 2, 222, 3, 333 }" << endl;
	cout << "������� �������� 1 � 2 �������������" << endl;
	TPolinom a1(a);
	TPolinom b1(b);
	cout << "1: "<<a1.ToString() << endl;
	cout << "2: "<<b1.ToString() << endl;
	cout << "�������� ����� �������� 1 - ������� 3" << endl;
	TPolinom c1(a1);
	cout << "3: "<<c1.ToString() << endl;
	cout << "������ �������� 1 � 2" << endl;
	c1 = a1 + b1;
	cout << c1.ToString() << endl;
	cout << "������� ������� 1 �� ����� 2" << endl;
	a1 = a1 * 2;
	cout << a1.ToString() << endl;*/




	//��� �������������
	int i, j;
	vector<int> v1, v2;
	cout << "������� ����������� ��������� � ������ ��������" << endl;
	cin >> i;
	cout << "������� ���������� � ������� ������� ��������" << endl;
	for (int i1 = 0; i1 < i * 2; i1++)
	{
		int u;
		cin >> u;
		v1.push_back(u);

	}
	cout << "������� ����������� ��������� �� ������ ��������" << endl;
	cin >> j;
	cout << "������� ���������� � ������� ������� ��������" << endl;
	for (int i1 = 0; i1 < j * 2; i1++)
	{
		int u;
		cin >> u;
		v2.push_back(u);

	}
	TPolinom p1(v1);
	TPolinom p2(v2);
	cout << "��������� �������� ���������:" << endl;
	p1 = p1 + p2;
	cout << p1.ToString();





}