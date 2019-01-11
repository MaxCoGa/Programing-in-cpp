#include <iostream>
using namespace std;

class Error {
public:
  int num;
};

class CodeError: public Error {
public:
  int code;
};

class A
{
public:
  A(int n) {
		if (n==1) {
			CodeError erd; erd.num = 999;
      erd.code = 12; throw erd;
		}
  }
};

int main() {
  try {
    A a(1);
    cout << "Created a(1)" << endl;
  }
  catch (Error e) {
    cout << "exception Error: " << e.num << endl;
  }
  catch (CodeError e) {
    cout << "exception CodeError: " << e.num << " " << e.code << endl;
  }
  catch (...) {
    cout << "Unknown Error"  << endl;
  }
  cout << "after" << endl;
  try { A b(1);
    cout << "Created b(1)" << endl;
  }
  catch (CodeError e) {
    cout << "exception CodeError: " << e.num << " " << e.code << endl;
  }
  catch (Error e) {
    cout << "exception Error: " << e.num << endl;
  }
  return 0;
}
