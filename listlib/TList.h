#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // ������ �����
	TNode<T>* pCurrent; // ������� �����
	TNode<T>* pPrevious; // ����� ����� �������
	TNode<T>* pLast; // ��������� �����
	TNode<T>* pStop; // �������� ���������, ����������� ����� ������
	int length=0; // ���������� ������� � ������

public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty(); // ������ ���� ?
	// ������� �������
	void InsertFirst(T item); // ����� ������
	void InsertCurrent(T item); // ����� ������� 
	void InsertLast(T item);  // �������� ��������� 

	// �������� �������
	void DeleteFirst(); // ������� ������ ����� 
	void DeleteCurrent(); // ������� ������� �����

	void GoNext(); // ����� ������ �������� �����
	// (=1 ����� ���������� GoNext ��� ���������� ����� ������)

	void Reset(); // ���������� �� ������ ������
	bool IsEnd();  // ������ �������� ?

	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }
	void InsertPrevCurrent(T item);
	void InsertNextCurrent(T item);


};
template <class T>
TList<T>::TList()
{
	pFirst = nullptr;
    pCurrent= nullptr; // ������� �����
	pPrevious= nullptr; // ����� ����� �������
	pLast= nullptr; // ��������� �����
	pStop=nullptr; // �������� ���������, ����������� ����� ������
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
void TList<T>::InsertLast(T item)//������� ������ ������ ����� ���
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
void TList<T>::DeleteFirst()//�� �������
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
		DeleteFirst();//�����������
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
void TList<T>::Reset()//����� �� ����������
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
void TList<T>::InsertPrevCurrent(T item)//�������� �� ��������
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






