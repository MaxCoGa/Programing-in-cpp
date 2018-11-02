// ==========================================================================
// $Id: short.cpp,v 1.1 2017/10/29 19:14:58 jlang Exp $
// CSI2372 Solution code for midterm B
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   EECS, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada. 
//   http://www.eecs.uottawa.ca
// 
// Creator: jlang (Jochen Lang)
// Email:   jlang@eecs.uottawa.ca
// ==========================================================================
// $Log: short.cpp,v $
// Revision 1.1  2017/10/29 19:14:58  jlang
// First draft of midterm B.
//
// ==========================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void question1() {
	const int ci = 2;
	int j = ci;
	// ci = j;
	int i = 5;
	const int cj = i;
	// std::cin >> ci;
	return;
}


struct AA {
	int v[2];
	A() {}
};

void question2poor() {
	AA a;
	int m[2];
	std::cout << a.v[1] << endl;
	std::cout << m[1] << endl;
}


struct A {
	static int count;
	static int getAndIncrementCount() {
		return ++count;
	}
};

int A::count{0};

void question2() {
	cout << A::getAndIncrementCount() << endl;
}

#if 0
class LetterGrade {
	string d_mark{"INC"};
public:
	LetterGrade() = default;
	LetterGrade( string m ) : d_mark(m) {}
	string get() { return d_mark; }
	void set(string m) {d_mark = m;}
	bool pass() { if ( d_mark < "D" || d_mark == "D+") return true;	}
};
#endif

class LetterGrade {
	string d_mark{"INC"};
public:
	LetterGrade() = default;
	LetterGrade( const string& m ) : d_mark(m) {}
	string get() const { return d_mark; }
	void set(const string& m) {d_mark = m;}
	bool pass() const { if ( d_mark < "D" || d_mark == "D+") return true;	}
};

void question3() {
	LetterGrade L;
}


class Parent {
	int p{1};
public:
	virtual int getA() { return p; }		
	virtual int getB()=0;
	int getC() { return p; }
};

class Child : public Parent {
	int p{2};
public:
	int getA() { return p; }		
	int getB() override { return p; }
	int getC() { return p; }
};

void question4() {
	Child c;
	cout << c.getA() << " " << c.getB() << " " << c.getC() << endl;
}

void question5() {
	Child c;
	Parent& p = c;
	cout << p.getA() << " " << p.getB() << " " << p.getC() << endl;
}

void question6() {
	Child c;
	Parent& p = c;
	try { 
		auto u = dynamic_cast<Child&>(p);
	} catch (...) {
		std::cerr << "Downcast failed!" << endl;
	}
}

void question7() {
	std::ifstream ifs("text.txt");
	if ( !ifs ) {
		std::cerr << "File could not be opened" << std::endl;
	}
}


void question8() {
	string s{7};
	int i;
	std::istringstream sts{s};
	sts >> i;
}

int main() {
	// Which lines are in error
	question1();
	std::cout << "=====================================" << endl;  
	// Call the function getIncrementCount of struct A and print the result to console, what will be printed?
	question2();
	// Rewrite the function prototypes in the class Lettergrade using const and references as much as possible but not more.
	question3();
	// What is printed by the following?
	question4();
	// What is printed by the following?
	question5();
	// Modify the program to print "Downcast failed!" on failure of the dynamic cast 
	question6();
	// Open the file "text.txt" for reading and print "File could not be opened" on failure.
	question7();
	// Convert the string "7" to an integer using streams
	question8();
	return 0;
}
    
  


