#include <iostream>
#include "MySharedPtr.h"
using namespace std;

class Foo
{
private:

	int m_number;

public:
	Foo(int number) : m_number(number)
	{
	}

	int GetNumber()
	{
		return m_number;
	}
};

int main()
{
	/*std::shared_ptr<Foo> p1(new Foo(5));
	std::shared_ptr<Foo> p2;
	p2 = p1;*/

	MySharedPtr<Foo> p1(new Foo(5));
	MySharedPtr<Foo> p2;
	p2 = p1;

	cout << p1.GetCount() << endl;
	cout << p2.Get() << ' ' << p2.Get()->GetNumber() << endl;
	cout << p1.Get() << ' ' << p1.Get()->GetNumber() << endl;
}