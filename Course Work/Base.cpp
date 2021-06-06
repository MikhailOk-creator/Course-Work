#include "Base.h"
#include <iostream>
#include <string>
using namespace std;

Base::Base(Base* parent_, const string& name_)
{
	input_name(name_);
	parent = parent_;
	if (parent)
	{
		parent->kinder.push_back(this);
	}
}

void Base::input_name(const string& name_)
{
	name = name_;
}

string Base::output_name() const
{
	return name;
}

void Base::input_state(int state_)
{
	object_state = state_;
}

int Base::print_kinder() const
{
	if (parent == 0)
	{
		cout << output_name();
	}
	if (kinder.empty())
	{
		return 0;
	}
	cout << endl << name;
	for (const auto& item : kinder)
	{
		cout << " " << item->name;
	}
	kinder[kinder.size() - 1]->print_kinder();
}

void Base::kinder_state()
{
	cout << "The object " << name;
	if (object_state <= 0 && this->find_object(this->name) == this)
	{
		cout << " is not ready";
	}
	else
	{
		cout << " is ready";
	}
	if (!kinder.empty())
	{
		cout << endl;
		for (int i = 0; i < this->kinder.size(); ++i)
		{
			kinder[i]->kinder_state();
			if (i != kinder.size() - 1)
			{
				cout << endl;
			}
		}
	}
}

void Base::redefinition_parent(Base* parent_)
{
	int i = 0;
	while (this->parent->kinder[i]->output_name() != this->output_name())
	{
		i += 1;
	}
	this->kinder.erase(kinder.begin() + i);
	parent_->kinder.push_back(this);
	this->parent = parent_;
}

Base* Base::output_parent() const
{
	return parent;
}

Base* Base::find_object(string name_)
{
	if (this->name == name_)
	{
		return this;
	}
	for (int i = 0; i < this->kinder.size(); ++i)
	{
		Base* b = kinder[i]->find_object(name_);
		if (b != NULL)
		{
			return b;
		}
	}
	return nullptr;
}

void Base::perfect_kinder_print(int number_of_margins)
{
	if (number_of_margins == 0)
	{
		cout << "Object tree" << endl;
	}
	for (int number = 0; number < number_of_margins; number++)
	{
		cout << "    ";
	}
	cout << name;
	if (!kinder.empty())
	{
		cout << endl;
		for (int i = 0; i < this->kinder.size(); i++)
		{
			kinder[i]->perfect_kinder_print(number_of_margins + 1);
			if (i != kinder.size() - 1)
			{
				cout << endl;
			}
		}
	}
}

Base* Base::path_find_object(string name)
{
	if (name[1] == '//')
	{
		return this->find_object(name.substr(2, name.size() - 2));
	}
	int t = -1, t2 = name.size();
	for (int i = 1; i < name.size(); i++)
	{
		if (name[i] == '/')
		{
			if (t == -1)
			{
				t = i;
			}
			else
			{
				t2 = i;
				break;
			}
		}
	}
	if (t == -1)
	{
		return this;
	}
	string s2 = name.substr(static_cast<long long>(t) + 1, static_cast<long long>(t2) - static_cast<long long>(t) - 1);
	for (int i = 0; i < this->kinder.size(); i++)
	{
		if (this->kinder[i]->output_name() == s2)
		{
			return this->kinder[i]->path_find_object(name.substr(static_cast<long long>(t) + 1, name.size() - t));
		}
	}
	return nullptr;
}

Base::~Base()
{
	if (this->kinder.size() != 0)
	{
		for (auto* Base : kinder)
		{
			delete Base;
		}
	}
}