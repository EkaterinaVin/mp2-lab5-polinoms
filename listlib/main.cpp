#include "TList.h"
int main()
{
	TList<int> *a = new TList<int>;
	a->InsertFirst(1);
	a->InsertFirst(2);
	a->InsertLast(3);
	while (a->IsEnd() == false)
	{
		cout << a->GetCurrentItem();
		a->GoNext();
	}
}