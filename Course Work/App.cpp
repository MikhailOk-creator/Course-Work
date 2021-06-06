#include "App.h"
#include "Derived.h"
#include <iostream>
#include <string>
#include "Class2.h"
#include "Class3.h"
#include "Class4.h"
#include "Class5.h"
#include "Class6.h"
using namespace std;

void App::set_up_program()
{
	string parent_name, child_name;
	cin >> parent_name;
	input_name(parent_name);
	Base* current_parent = this;
	Base* current_child = nullptr;
	while (true)
	{
		cin >> parent_name >> child_name;
		if (parent_name == child_name)
		{
			return;
		}
		if (parent_name != current_parent->output_name())
		{
			if (parent_name == current_child->output_name())
			{
				current_parent = current_child;
			}
			else
			{
				continue;
			}
		}
		current_child = new Derived(child_name, current_parent);
	}
}

void App::read_data()
{
	string parent_name, child_name;
	Base* current_parent = this;
	Base* current_child = nullptr;
	cin >> parent_name;
	if (this->output_parent() == nullptr)
	{
		input_state(1);
	}
	input_name(parent_name);
	cin >> parent_name;
	while (parent_name != "endtree")
	{
		int class_oo, state;
		cin >> child_name >> class_oo >> state;
		current_parent = this->find_object(parent_name);
		if (find_object(child_name) == nullptr)
		{
			switch (class_oo)
			{
			case 2:
				current_child = new Class2(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 3:
				current_child = new Class3(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 4:
				current_child = new Class4(current_parent, child_name);
				current_child->input_state(state);
				break;
			}
		}
		cin >> parent_name;
	}
}

int App::start() const
{
	//cout << output_name();
	this->print_kinder();
	return 0;
}

int App::checking_readiness()
{
	cout << "Test result" << endl;
	this->kinder_state();
	return 0;
}

void App::read_data_2()
{
	string parent_name, child_name;
	Base* current_parent = this;
	Base* current_child = nullptr;
	cin >> parent_name;
	if (this->output_parent() == nullptr)
	{
		input_state(1);
	}
	input_name(parent_name);
	cin >> parent_name;
	while (parent_name != "endtree")
	{
		int class_oo, state;
		cin >> child_name >> class_oo >> state;
		current_parent = this->find_object(parent_name);
		if (find_object(child_name) == nullptr)
		{
			switch (class_oo)
			{
			case 2:
				current_child = new Class2(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 3:
				current_child = new Class3(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 4:
				current_child = new Class4(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 5:
				current_child = new Class5(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 6:
				current_child = new Class6(current_parent, child_name);
				current_child->input_state(state);
				break;
			}
		}
		cin >> parent_name;
	}
}

void App::read_data_3()
{
	string parent_name, child_name;
	Base* current_parent = this;
	Base* current_child = nullptr;
	cin >> parent_name;
	if (this->output_parent() == nullptr)
	{
		input_state(1);
	}
	input_name(parent_name);
	cin >> parent_name;
	while (parent_name != "endtree")
	{
		int class_oo, state;
		cin >> child_name >> class_oo >> state;
		current_parent = this->path_find_object(parent_name);
		if (find_object(child_name) == nullptr)
		{
			switch (class_oo)
			{
			case 2:
				current_child = new Class2(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 3:
				current_child = new Class3(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 4:
				current_child = new Class4(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 5:
				current_child = new Class5(current_parent, child_name);
				current_child->input_state(state);
				break;
			case 6:
				current_child = new Class6(current_parent, child_name);
				current_child->input_state(state);
				break;
			}
		}
		cin >> parent_name;
	}
}

int App::print_full_tree()
{
	this->perfect_kinder_print();
	return 0;
}

int App::the_strange_print()
{
	this->perfect_kinder_print();
	string s1;
	cin >> s1;
	while (s1 != "//")
	{
		cout << endl;
		Base* b = this->path_find_object(s1);
		cout << s1;
		if (b != NULL)
		{
			cout << " Object name: " << b->output_name();
		}
		else
		{
			cout << " Object not found";
		}
		cin >> s1;
	}
	return 0;
}
