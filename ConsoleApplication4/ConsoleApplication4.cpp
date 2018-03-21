//problem 
#include "stdafx.h"
class a
{
	int ma = 0;
};
class b : public a
{
	virtual void e() {}
	int mb = 0;
};
class c : public b,public a
{
	virtual void e() {}
	int mc = 0;
};
class d : public b
{
	virtual void e() {}
	int md = 0;
};
int main()
{
	c * p = new c();
	d * p2 = new d();
	a * pa = dynamic_cast<a *>(p); 
	a * pa2 = dynamic_cast<a *>(p2);
    return 0;
}

