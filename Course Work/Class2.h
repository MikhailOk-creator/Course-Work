#pragma once
#ifndef CLASS_2
#define CLASS_2
#include "Base.h"
class Class2 : public Base
{
public:
	Class2(Base* parent_, const string& a) :Base(parent_, a) {};
};
#endif