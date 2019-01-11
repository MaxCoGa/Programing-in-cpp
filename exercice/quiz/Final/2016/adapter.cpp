#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class T>
class SLL : protected std::vector<T> {

public:
	// add at the end of the vector
	void add(T& entry);
	// return the element at the end of the vector
	T peek();
	// return and remove element at the end of the vector
	T get();
	// clear the whole vector
	void clear();
	// find the index in the vector of an element or return -1
	// assumes T has an equality operator
	size_t index_of( const T& );
	// find an element and return an iterator to it; returns
	// na iteraor to end on failure
	// assumes T has an equality operator
	typename std::vector<T>::const_iterator iter( const T& ); 

	// return this SLL as a std::list 
	std::list<T> toList();
	
	// just for debugging
	friend ostream& operator<<( ostream& os, const SLL<T>& sll ) {
		for ( const T& e:sll ) {
			os << e << " ";
		}
		return os;
	}
};


template <class T>
void SLL<T>::add(T& entry ) {
	std::vector<T>::push_back(entry);
}

template <class T>
T SLL<T>::peek() {
	return *this->rend();
}

template <class T>
T SLL<T>::get() {
	T last{*this->rend()};
	erase(*this->rend());
	return last;
}

template <class T>
void SLL<T>::clear() {
	std::vector<T>::clear();
	return;
}

template <class T>
size_t  SLL<T>::index_of( const T& e ) {
	auto iter = std::find( this->cbegin(), this->cend(), e);
	if ( iter == this->end() ) return -1; 
	return iter-this->begin();
}

template <class T>
typename std::vector<T>::const_iterator SLL<T>::iter( const T& e ) { 
	return std::find( this->cbegin(), this->cend(), e);
}

// return SLL as a std::array
template <class T>
std::list<T> SLL<T>::toList() {
	//	return std::list<T>( this->begin(), this->end() );
	std::list<T> l;
	std::copy( this->cbegin(), this->cend(), l.begin());
	return l;
}



int main() {
	SLL<int> l;

	for ( int i=0; i<5; ++i ) {
		l.add(i);
	}
	cout << l << endl;

	for ( int i=0; i<5; ++i ) {
		cout << i << " Position: " << l.index_of(i) << endl;
	}

	auto start = l.iter(3);
	cout << "Iterator 3: " << *start << endl;

	auto ll = l.toList();
	for ( auto e:ll) {
		cout << e << " ";
	}
	cout << endl;
	
	return 0;
}
