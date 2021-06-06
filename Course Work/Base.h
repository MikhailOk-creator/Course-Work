#ifndef BASE_H
#define BASE_H
#include <string>
#include <vector>
using namespace std;
class Base
{
private:
	string name;
	Base* parent;
	vector<Base*>kinder;
	int object_state;
public:
	explicit Base(Base* parent_, const string& name_ = "root");
	void input_name(const string& name_);
	string output_name() const;
	void input_state(int state_);
	int print_kinder() const;
	void kinder_state();
	void redefinition_parent(Base* parent_);
	Base* output_parent() const;
	Base* find_object(string name);
	void perfect_kinder_print(int number_of_margins = 0);
	Base* path_find_object(string name);
	~Base();
};
#endif