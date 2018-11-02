#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;
using std::endl;
using std::cout;

class StringStore;
std::ostream& operator<<( std::ostream& os, const StringStore& stS);

class StringStore {
	std::string* d_store{0};
	size_t d_size{0};
	size_t d_capacity{0};
public:
	StringStore() = default;
	StringStore(const StringStore& oStS );
	StringStore& operator=(const StringStore& oStS);
	~StringStore();
	StringStore(std::vector<std::string>& sVec ); 
	void add(string str);
	friend std::ostream& operator<<( std::ostream& os, const StringStore& stS);
};


StringStore::~StringStore() {
	delete[] d_store;
}

StringStore::StringStore(const StringStore& oStS ) : 
	d_store{new string[oStS.d_capacity]}, d_size{oStS.d_size}, d_capacity{oStS.d_capacity} 
{
	for (int i=0; i<oStS.d_size; ++i ) {
		d_store[i] = oStS.d_store[i];
	}
} 
	
StringStore::StringStore(std::vector<string>& sVec ) : 
	d_store{new string[sVec.size()]}, d_size{sVec.size()}, d_capacity{sVec.size()} 
{
	int i=0;
	for ( auto& s:sVec) {
		d_store[i++] = s;
	}
} 

StringStore& StringStore::operator=( const StringStore& oStS) {
	if ( this != &oStS ) {
		delete[] d_store;
		d_store = new string[oStS.d_capacity];
		d_capacity = oStS.d_capacity;
		for ( int i=0; i<oStS.d_size; ++i ) {
			d_store[i] = oStS.d_store[i];
		}
		d_size = oStS.d_size;
	}
	return *this;
}

void StringStore::add(string str) {
	if ( d_size+1 > d_capacity ) {
		size_t ns = std::max(static_cast<size_t>(1),2*d_size);
		string* store = new  string[ns];
		for ( int i=0; i<d_size; ++i ) {
			store[i] = d_store[i];
		}
		delete[] d_store;
		d_store = store;
		d_capacity = ns;
	}
	d_store[d_size] = str;
	++d_size;
	return;
}

ostream& operator<<( ostream& os, const StringStore& stS) {
	for (int i=0; i<stS.d_size; ++i ) {
		os << stS.d_store[i] << endl;
	}
}
	
class Route;
ostream& operator<<( ostream& os, const Route& rt);	
	
class Route : protected StringStore {
	string d_destination;
	string d_start;
public:
	Route() = delete;
#if 0
	Route(const Route& oR);
	~Route();
	Route& operator=( const Route& oR);	
#endif
	Route(std::vector<string>& streetNames, string start, string destination);
	void add(string streetName );
	friend ostream& operator<<( ostream& os, const Route& rt);
};

Route::Route( std::vector<string>& streetNames, string start, string destination ) : 
	StringStore{streetNames}, d_start{start}, d_destination{destination} 
{} 

#if 0
Route::Route(const Route& oR) : StringStore(oR), d_start(start), d_destination(destination) {
}


Route& Route::operator=( const Route& oR) {
	if ( this != &oR ) {
		StringStore::operator=(oR);
		d_start = oR.d_start;
		d_destination = oR.d_destination;
	}
	return *this;
}

Route::~Route() {
}
#endif

void Route::add(string streetName) {
	StringStore::add(streetName);
	return;
}

ostream& operator<<( ostream& os, const Route& rt) {
	os << "From: " << rt.d_start << " to " << rt.d_destination << endl;
	os << static_cast<StringStore>(rt);
}

int main() {
	std::vector<string> streetsA{"Wellington","Bronson","Laurier"};
	Route rtA{streetsA,"Home","School"};
	rtA.add( "King Edward");
	cout << rtA;
	cout << "===================================" << endl;
	std::vector<string> streetsB{"King Edward", "Vanier"};
	Route rtB{ streetsB, "School", "Friend" };
	cout << rtB;	
	cout << "===================================" << endl;
	rtB = rtA;
	cout << rtB;	
	return 0;
}


