#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // первое звено
	TNode<T>* pCurrent; // текущее звено
	TNode<T>* pPrevious; // звено перед текущим
	TNode<T>* pLast; // последнее звено
	TNode<T>* pStop; // значение указателя, означающего конец списка
	int length=0; // количество звеньев в списке

public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty(); // список пуст ?
	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим 
	void InsertLast(T item);  // вставить последним 

	// удаление звеньев
	void DeleteFirst(); // удалить первое звено 
	void DeleteCurrent(); // удалить текущее звено

	void GoNext(); // сдвиг вправо текущего звена
	// (=1 после применения GoNext для последнего звена списка)

	void Reset(); // установить на начало списка
	bool IsEnd();  // список завершен ?

	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }
	void InsertPrevCurrent(T item);
	void InsertNextCurrent(T item);


};
template <class T>
TList<T>::TList()
{
	pFirst = nullptr;
    pCurrent= nullptr; // текущее звено
	pPrevious= nullptr; // звено перед текущим
	pLast= nullptr; // последнее звено
	pStop=nullptr; // значение указателя, означающего конец списка
	length=0;

}

template <class T>
TList<T>::~TList()
{
	TNode<T>* p;
	while (pFirst != nullptr) {
		p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
	}

}

template <class T>
bool TList<T>::IsEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	TNode<T>* node = new TNode<T>;
	node->value = item;
	node->pNext = pFirst;
	pFirst = node;
	if (IsEmpty())
	{
		pLast = pFirst;
		pStop = new TNode<T>;
		pFirst->pNext = pStop;
		pStop->pNext = nullptr;
	}


}

template <class T>
void TList<T>::InsertLast(T item)//проверь ошибка скорее всего тут
{
	TNode<T>* node = new TNode<T>;
	node->value = item;
	pPrevious=pLast;
	pLast = node;
	pPrevious->pNext = pLast;
	if (IsEmpty())
	{
		pLast = pFirst;
		pStop = new TNode<T>;
		pStop->pNext = nullptr;
	}
	else
		pLast->pNext = pStop;
	length++;

}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	TNode<T>* node = new TNode<T>;
	node->value = item;

	if (pCurrent == pFirst) {
		node->pNext = pFirst;
		pFirst = node;
	}
	else {
		pPrevious->pNext = node;
		node->pNext = pCurrent;
	}
	length++;
	
}

template <class T>
void TList<T>::DeleteFirst()//не уверена
{
	if (IsEmpty() == false) {
		pFirst = pFirst->pNext;
		length--;
		if (length == 0) {
			pLast = nullptr;
			pStop = nullptr;
		}

	}
	else
		throw("List is empty");

}

template <class T>
void TList<T>::DeleteCurrent()
{
	if (pCurrent == pFirst)
	{
		DeleteFirst();//сомнительно
	}
	else
	{
		pPrevious->pNext = pCurrent->pNext;
		pCurrent = pCurrent->pNext;
		length--;
	}
	if (pCurrent == pLast) {
		pLast = pPrevious;
		length--;
	}
	
}

template <class T>
T TList<T>::GetCurrentItem()
{
	if (pCurrent == pStop)
		throw " ";
	if (pCurrent == nullptr) 
		throw " ";
	return pCurrent->value;
}

template <class T>
void TList<T>::Reset()//такой ли функционал
{
	pCurrent = pFirst;
	pPrevious = nullptr;
}

template <class T>
void TList<T>::GoNext()
{
	pPrevious = pCurrent;
	pCurrent = pCurrent->pNext;
}

template <class T>
bool TList<T>::IsEnd()
{
	if (pCurrent->pNext == pStop)
		return true;
	return false;
}
template <class T>
void TList<T>::InsertPrevCurrent(T item)//добавить до текущего
{
	TNode<T>* node = new TNode<T>;
	node->value = item;

	if (pCurrent == pFirst) {
		node->pNext = pFirst;
		pFirst = node;
	}
	else {
		pPrevious->pNext = node;
		node->pNext = pCurrent;
	}
	length++;
}
template <class T>
void TList<T>::InsertNextCurrent(T item)
{
	TNode<T>* newNode = new TNode<T>;
	newNode->value = item;
	if (pCurrent == pLast) {
		newNode->pNext = nullptr;
		pLast->pNext = newNode;
		pLast = newNode;
	}
	else {
		newNode->pNext = pCurrent->pNext;
		pCurrent->pNext = newNode;
	}
	length++;
}






