#include "stdafx.h"

template<bool> struct ComplitTimeChecker
{
	ComplitTimeChecker(...) {}
};

//全特化
template<> struct ComplitTimeChecker<false> {};

#define  STATIC_CHECK(expr,msg)\
		{\
			class ERROR_##msg{};\
			(void)sizeof(ComplitTimeChecker<(expr)>(new ERROR_##msg()));\
		}

template<class To,class From>
To safe_reinterpret_cast(From from)
{
	STATIC_CHECK(sizeof(From)<=sizeof(To),Destination_Type_Too_Narrow);
	return reinterpret_cast<To>(from);
}

template<typename Checker,typename Type>
class Base
{
public:
	Base() { printf("Base..."); }
};

//偏特化
template<typename Checker>
class Base<Checker,int>
{
public:
	Base() { printf("偏特化Base..."); }
};

template<int type>
struct Int2Type
{
	enum {value = type};
};

class c
{
private:
	c();
	int a;
};

struct B
{
	B(...);
	long b;
};


int main()
{ 
	/*char a = 1;
	char * smallPoint = &a;
	char  c = safe_reinterpret_cast<char >(smallPoint);*/

	Base<char, char> bs;
	c cc();
	auto i = sizeof(B(cc()));
    return 0;
}

