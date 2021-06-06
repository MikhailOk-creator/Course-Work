#pragma once
#ifndef CLASS_3
#define CLASS_3
#include "Base.h"
class Class3 : public Base
{
public:
	Class3(Base* parent_, const string& a) :Base(parent_, a) {};
};
#endif