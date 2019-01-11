#include <iostream> 

using namespace std; 

class A {
protected:
	int d_a = 1;
public: 
  virtual A& operator+=(int i) {
		d_a += i;
		cout << "A: " << d_a << endl;
		return *this;
	} 
}; 

class B : public A {
public: 
  virtual B& operator+=(double d) {
		d_a += 2*static_cast<int>(d);
		cout << "B: " << d_a << endl;
		return *this;
	} 
}; 

int main () {
  B ab;
	A& a = ab;
	A aa = ab;
	A* aptr = &ab;
	ab += 1;
	a += 1.0;
	(*aptr) += 1;
	aa += 1;
	return 0;
} 
