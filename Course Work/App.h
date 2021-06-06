#ifndef APP_H
#define APP_H
#include "Base.h"
#include <string>
class App : public Base
{
public:
	using Base::Base;
	void set_up_program();
	void read_data();
	void read_data_2();
	void read_data_3();
	int checking_readiness();
	int print_full_tree();
	int the_strange_print();
	int start() const;
};
#endif