#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::endl;

class Pair {
public:
	int p1, p2;
	Pair() : p1(0), p2(0) {
		cout << "Empty" << endl;
	}
	Pair(int a, int b=0) : p1(a), p2(b) {
		cout << "Full" << endl;
	}
	Pair(const Pair& p) {
		p1= p.p1; p2= p.p2;
		cout << "Copy" << endl;
	}
	Pair& operator=(const Pair& p) {
		if (this != &p) {
			p1= p.p1; p2= p.p2;
		}
		cout << "Assignment" << endl;;
		return *this;
	}
};

void fct1(Pair& p) {
	p.p1 =0;
}

Pair fct2() {
	return Pair(2);
}

void fct3(Pair p) {
	p.p1= 0;
}

int main()
{
	cout << "Question 1.1" << endl;
	Pair pairs1[3];
	cout << "Question 1.2" << endl;
	Pair p(1,2);
	cout << "Question 1.3" << endl;
	Pair pairs2{(1,2),(3,4)};
	cout << "Question 1.4" << endl;
	std::vector<Pair> v(4,4);
	cout << "Question 1.5" << endl;
	p= v[0];
	cout << "Question 1.6" << endl;
	v[1]=p;
	cout << "Question 1.7" << endl;
	v.pop_back(); v.pop_back(); v.pop_back();
	cout << "Question 1.8" << endl;
	v.push_back(pairs1[1]);
	cout << "Question 1.9" << endl;
	std::shared_ptr<Pair> ptr1(new Pair(3));
	cout << "Question 1.10" << endl;
	std::shared_ptr<Pair> ptr2(ptr1);
	cout << "Question 1.11" << endl;
	fct1(p);
	cout << "Question 1.12" << endl;
	p= fct2();
	cout << "Question 1.13" << endl;
	fct3(p);
	cout << "Question 1.14" << endl;
	Pair *ptr3= &p;
	return 0;
}
