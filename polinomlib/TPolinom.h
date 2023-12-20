#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

const int nonDisplayedZeros = 4; //  оличество неотображаемых нулей при выводе коэффициента полинома
								 //  ол-во символов после зап€той = 6 - nonDisplayedZeros


class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(vector<int> v);
	TPolinom& operator=(TPolinom& other); // присваивание
	TPolinom operator+(TPolinom& q); // сложение полиномов

	// дополнительно можно реализовать:
	void AddMonom(TMonom newMonom); // добавление монома
	//TPolinom MultMonom(TMonom monom); // умножение мономов
	TPolinom AddPolinom(TPolinom& other); // добавление полинома
	TPolinom operator*(int coef); // умножение полинома на число
	//TPolinom operator* (TPolinom& other); // умножение полиномов
	bool operator==(TPolinom& other); // сравнение полиномов на равенство
	string ToString(); // перевод в строку
	
};

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{

	length = 0;
	

}

TPolinom::TPolinom(TPolinom& other)
{
	int sz = other.GetLength();
	pStop = nullptr;
	other.Reset();
	TMonom start;
	start = other.GetCurrentItem();
	other.GoNext();
	InsertFirst(start);
	Reset();
	for (int i = 1; i < sz; i++) {
		TMonom a;
		a = other.GetCurrentItem();
		InsertNextCurrent(a);
		GoNext();
		other.GoNext();
	}
	Reset();
	other.Reset();
	
	

}

TPolinom::TPolinom(vector<int> v )///предполагаетс€, что это строка 1 и 3
{	
	int s = 1;
	int si = 1;
	int sz = v.size();
	TMonom mon;
	pStop = nullptr;
	TMonom start(v[0], v[1]);
	InsertFirst(start);
	Reset();
	for (int i = 2; i < sz; i =i+ 2) {
		int ind1 = v[i+1];
		Reset();
		TMonom first;
		first = GetCurrentItem();
		int ind = first.GetIndex();
		if (ind1 > ind) 
		{ 
			InsertFirst(TMonom(v[i], v[i+1]));
		    s++; 
		}
		else
		{
			while (ind1 < ind) {
				if (si < s) {
					GoNext();
					si++;
					mon = GetCurrentItem();
					ind = mon.GetIndex();
				}
				else {
					InsertLast(TMonom(v[i], v[i + 1]));
					s++; 
					return;
				}
			}

			if (ind == ind1) {
				if (si == 1) {
					first.SetCoef(first.GetCoef() + v[i]);
					InsertFirst(first);
					Reset();
					GoNext();
					DeleteCurrent();
				}
				else
				{
					mon.SetCoef(mon.GetCoef() + v[i]);
					DeleteCurrent();
					InsertPrevCurrent(mon);
				}
			}
			else
			{
				InsertPrevCurrent(TMonom(v[i], v[i + 1]));
				s++;
			}

		}
		si = 1;
	}
	Reset();

	
}


TPolinom& TPolinom::operator=(TPolinom& other)
{
	int k = GetLength();
	for (int i = 0; i < k; i++)
	{
		DeleteFirst();
	}
	int sz = other.GetLength();
	other.Reset();
	TMonom start;
	start = other.GetCurrentItem();
	other.GoNext();
	InsertFirst(start);
	Reset();
	for (int i = 1; i < sz; i++) {
		TMonom a;
		a = other.GetCurrentItem();
		InsertNextCurrent(a);
		GoNext();
		other.GoNext();
	}

	return *this;
}

void TPolinom::AddMonom(TMonom m)
{
	int ind1 = m.GetIndex();
	int si = 1;
	TMonom mon;
	Reset();
	TMonom first;
	first = GetCurrentItem();
	int ind = first.GetIndex();
	if (ind1 > ind)
	{
		InsertFirst(TMonom(m));
	}
	else
	{
		while (ind1 < ind) {
			if (si < GetLength()) {
				GoNext();
				si++;
				mon = GetCurrentItem();
				ind = mon.GetIndex();
			}
			else {
				InsertLast(TMonom(m));
				return;
			}
		}

		if (ind == ind1) {
			if (si == 1) {
				first.SetCoef(first.GetCoef() + m.GetCoef());
				InsertFirst(first);
				Reset();
				GoNext();
				DeleteCurrent();
			}
			else
			{
				mon.SetCoef(mon.GetCoef() + m.GetCoef());
				DeleteCurrent();
				InsertPrevCurrent(mon);
			}
		}
		else
		{
			InsertPrevCurrent(TMonom(m));
		}

	}
}

////TPolinom TPolinom::MultMonom(TMonom monom)//no
//{
//	return *this;
//}

TPolinom TPolinom::operator+(TPolinom& other)
{
	TPolinom result = *this;
	int sz = other.GetLength();
	other.Reset();
	for (int i = 0; i < sz; i++)
	{
		TMonom mon;
		mon = other.GetCurrentItem();
		other.GoNext();
		result.AddMonom(mon);

	}
	return result;
}

TPolinom TPolinom::AddPolinom(TPolinom& other)
{
	int sz = other.GetLength();
	other.Reset();
	for (int i = 0; i < sz; i++)
	{
		TMonom mon;
		mon = other.GetCurrentItem();
		other.GoNext();
		AddMonom(mon);

	}
	return *this;
}

TPolinom TPolinom::operator*(int coef1)
{
	TPolinom result = *this;
	result.Reset();
	for (int i = 0; i < length; i++)
	{
		TMonom a;
		a.SetCoef(GetCurrentItem().GetCoef() * coef1);
		a.SetIndex(GetCurrentItem().GetIndex());
		GoNext();
		result.SetCurrentItem(a);
	    result.GoNext();
	}
	return result;
}

//TPolinom TPolinom::operator*(TPolinom& other)//no
//{
//	return *this;
//}

bool TPolinom::operator==(TPolinom& other)
{
	if (GetLength() != other.GetLength())
		return false;
	else
	{
		Reset();
		other.Reset();
		for (int i = 0; i < length; i++)
		{
			if (GetCurrentItem() != other.GetCurrentItem())
				return false;
		}
	}
	return true;
}


string TPolinom::ToString()
{
	string result;
	int sz = GetLength();
	Reset();
	for (int i = 0; i < sz; i++) {
		TMonom a;
		a = GetCurrentItem();
		int A = a.GetCoef();
		std::ostringstream oss;
		oss << A;
		int ind = a.GetIndex();
		result += oss.str();
		result += "x^";
		result += std::to_string((ind - ind % 100) / 100);
		result += "y^";
		result += std::to_string(((ind % 100) - (ind % 10)) / 10);
		result += "z^";
		result += std::to_string(ind % 10);
		if (i != sz - 1)
			result += " + ";
		if (i < sz - 1)
			GoNext();
	}
	return result;
}
