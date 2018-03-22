//±‡“Î ±¥ÌŒÛºÏ≤È
#include "stdafx.h"

template<bool> struct ComplitTimeChecker
{
	ComplitTimeChecker(...) {}
};

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

int main()
{ 
	char a = 1;
	char * smallPoint = &a;
	char  c = safe_reinterpret_cast<char >(smallPoint);
    return 0;
}

