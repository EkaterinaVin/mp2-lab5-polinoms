#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;  // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>{};
	this->pFirst = pHead->pNext;
	this->pStop = new TNode<T>{};
	this->pLast = this->pStop;
	this->pCurrent = this->pFirst;
	this->length = 0;
}

template<class T>
THeadList<T>::~THeadList()
{

}

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TNode<T>* node = new TNode<T>;
	node->value = item;
	node->pNext = this->pFirst;
	this->pFirst = node;
	this->length++;
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	if (this->IsEmpty()) {
		throw "list is empty";
	}
	TNode<T>* temp = this->pFirst;
	this->pFirst = this->pFirst->pNext;
	delete temp;
	this->length--;
}