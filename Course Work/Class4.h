#pragma once
#ifndef CLASS_4
#define CLASS_4
#include "Base.h"
class Class4 : public Base
{
public:
	Class4(Base* parent_, const string& a) :Base(parent_, a) {};
};
#endif