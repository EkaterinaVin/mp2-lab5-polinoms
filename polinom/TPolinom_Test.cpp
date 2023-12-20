#include <iostream>
#include "TList.h"
#include "TPolinom.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");


	// здесь должна быть проверка работоспособности написанных вами классов
	
	/*cout << "Создадим два полинома на основе векторов a и b" << endl;
	vector<int> b = { 1, 111, 2, 222, 2, 111, 3, 222 };
	vector<int> a = { 1, 111, 2, 222, 3, 333 };
	cout << " 2 = { 1, 111, 2, 222, 2, 111, 3, 222 }" << endl;
	cout << "1 = { 1, 111, 2, 222, 3, 333 }" << endl;
	cout << "Получим полиномы 1 и 2 соответсвенно" << endl;
	TPolinom a1(a);
	TPolinom b1(b);
	cout << "1: "<<a1.ToString() << endl;
	cout << "2: "<<b1.ToString() << endl;
	cout << "Создадим копию полинома 1 - полином 3" << endl;
	TPolinom c1(a1);
	cout << "3: "<<c1.ToString() << endl;
	cout << "Сложим полиномы 1 и 2" << endl;
	c1 = a1 + b1;
	cout << c1.ToString() << endl;
	cout << "Умножим полином 1 на число 2" << endl;
	a1 = a1 * 2;
	cout << a1.ToString() << endl;*/




	//для пользователей
	int i, j;
	vector<int> v1, v2;
	cout << "Введите колличество элементов в первом полиноме" << endl;
	cin >> i;
	cout << "Введите коэфиценты и степени первого полинома" << endl;
	for (int i1 = 0; i1 < i * 2; i1++)
	{
		int u;
		cin >> u;
		v1.push_back(u);

	}
	cout << "Введите колличество элементов во втором полиноме" << endl;
	cin >> j;
	cout << "Введите коэфиценты и степени второго полинома" << endl;
	for (int i1 = 0; i1 < j * 2; i1++)
	{
		int u;
		cin >> u;
		v2.push_back(u);

	}
	TPolinom p1(v1);
	TPolinom p2(v2);
	cout << "Результат сложения полиномов:" << endl;
	p1 = p1 + p2;
	cout << p1.ToString();





}