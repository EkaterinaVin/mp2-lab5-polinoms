#pragma once
struct TMonom
{
	double coef; // коэффициент монома
	int index; // индекс (свертка степеней)


	TMonom() {
		coef = 0;
		index = 0;
	}
	TMonom(const TMonom& other) {
		coef = other.coef;
		index = other.index;
	}
	TMonom(int a) {
		coef = a/1000;
		index = a&1000;
	}
	
	TMonom(double coef1, int deg)
	{
		coef = coef1;
		index = deg;

	}

	TMonom(double coef1, int degX, int degY, int degZ)
	{ 
		coef = coef1;
		index = degX * 100 + degY * 10 + degZ;

	}

	void SetCoef(int cval) { coef = cval; }
	int GetCoef(void) { return coef; }

	void SetIndex(int ival) { index = ival; }
	int GetIndex(void) { return index; }


	bool operator==(const TMonom& other) 
	{
		if (coef == other.coef && index == other.index)
			return true;
		else
			return false;
	
	}
	bool operator!=(const TMonom& other)
	{
		if (coef == other.coef && index == other.index)
			return false;
		else
			return true;

	}
	void operator=(const TMonom& other)
	{
		coef = other.coef;
		index = other.index;
	}
	bool operator>(const TMonom& other) 
	{
		if (index > other.index)
			return true;
		if (coef > other.coef)
			return true;
		return false;
	}

	bool operator<(const TMonom& other) 
	{ 
		if (index > other.index)
			return false;
		if (coef > other.coef)
			return false;
		return true;
	}
	int intMonom()
	{
		return coef * 1000 + index;
	}


};