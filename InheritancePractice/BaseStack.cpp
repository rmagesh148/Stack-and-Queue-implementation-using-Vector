#include<iostream>
#include<vector>
using namespace std;
class BaseStack
{
protected:
	vector<int> stack;

public:
BaseStack()
{
}
~BaseStack()
{
}
void push(int num)
{
	stack.push_back(num);
	cout << "Value of the pushed element" << num << endl;
}
int pop() {
	int n;
	n = stack.front();
	//stack.pop_back();
	stack.erase(stack.begin());
	return n;
}
};
class DerivedStack :BaseStack
{
public:

	void push(int n) {
			BaseStack::push(n);
			cout << "Inserted into Stack" << endl;
	}
	int pop() {
		if (stack.empty()) {
			cout << "Stack is empty" << endl;
		}
		else {
			cout<<"Value of the popped element"<<BaseStack::pop()<<endl;
		}
		return 0;
	}
	void showStack()
	{
		for (auto i = stack.begin(); i != stack.end();i++)
			cout<<endl<<"Value of the stack"<<*i<<endl;
	}
};
int main()
{
	DerivedStack d1;
	for (int i = 0; i < 1000; i=i + 100) {
		d1.push(i);
	}
	d1.pop();
	d1.pop();
	d1.pop();
	d1.showStack();
	return 0;
}