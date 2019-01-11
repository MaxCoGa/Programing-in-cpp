#include <iostream>

using namespace std;

class Hike;

// Global operators declarations
ostream& operator<<( ostream&, const Hike& );
istream& operator>>( istream&, const Hike& );
// add two hikes by distance and elevationGain  
Hike operator+( const Hike&, const Hike& );
// add hike and some distance in kilometers
Hike operator+( const Hike&, float);
// add hike and some elevation gain
Hike operator+( const Hike&, int);


class Hike {
	float d_distance; // distance in kilometers
	int d_elevation; // elevation gain in meters
public:
	Hike() = default;

	explicit Hike(float distance, int elevation=0); 

	// add distances and elevationGain together 
	Hike& operator+=( Hike& );

	// increase the elevation gain by 1
	Hike& operator++();
	Hike operator++(int);
	
	// hike distance as float
	inline operator float() const;
	// hike elevation as int 
	inline operator int() const; 
	
	// print distance in miles and elevation gain in feet
	void imperial( ostream& os ) const;

	// stream insertion and extration
	// read/print distance and elevation gain directly
	friend ostream& operator<<( ostream&, const Hike& );
	friend istream& operator>>( istream&, Hike& );

protected:
	// convert distance from kilometers to miles; 1 mile = 1.609 km
	static float convert( float );
	// convert elevation gain from meters to feet; 1 foot = 0.3m
	static int convert( int );
};




// definitions
Hike::Hike(float distance, int elevation) :
	d_distance{distance}, d_elevation{elevation}
{}

Hike& Hike::operator+=( Hike& h) {
	d_distance += h.d_distance;
	d_elevation += h.d_elevation;
	return *this;
}

Hike& Hike::operator++() {
	d_elevation += 1;
	return *this;
}

Hike Hike::operator++(int) {
	Hike res(*this);
	d_elevation += 1;
	return res;
}

Hike::operator float() const {
	return d_distance;
}

Hike::operator int() const {
	return d_elevation;
}


void Hike::imperial( ostream& os ) const {
	os << "Hike: " << convert(d_distance) << " "
		 << convert(d_elevation) << endl;
}

// static protected methods
float Hike::convert( float km) {
	return km / 1.609;
}
	// convert elevation gain from meters to feet; 1 foot = 0.3m
int Hike::convert( int e) {
	return e>0?(e/0.3)+0.5:(e/0.3)-0.5;
}


// Global operators

ostream& operator<<( ostream& os, const Hike& h) {
	os << h.d_distance << " " << h.d_elevation;
	return os;
}


istream& operator>>( istream& is, Hike& h) {
	is >> h.d_distance >> h.d_elevation;
	if ( !is ) h = Hike();
	return is;
}


Hike operator+( const Hike& a, const Hike& b) {
	return Hike(static_cast<float>(a) + static_cast<float>(b),
							static_cast<int>(a) + static_cast<int>(b));
}

Hike operator+( const Hike& h, float d) {
	return Hike(static_cast<float>(h) + d,
							static_cast<int>(h));
}

Hike operator+( const Hike& h, int e) {
	return Hike(static_cast<float>(h),
							static_cast<int>(h) + e);
}


int main() {
	Hike walk(12.5f,350), up(25.0f,780), down(6.3f,-300);

	cout << walk << endl;
	up += down;	cout << up << endl;
	Hike upLong = up + 3.3f; cout << upLong << endl;
	Hike upup = up + 750;	cout << upup << endl;

	cout << "Enter a walk: ";	cin >> walk;
	cout << walk << endl;
	
	walk.imperial( cout );
	return 0;
}
