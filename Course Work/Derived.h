#ifndef DERIVED_H
#define DERIVED_H
#include "Base.h"
using namespace std;
class Derived : public Base
{
public:
	Derived(const string& name_, Base* parent_) : Base(parent_, name_) {}
};
#endif