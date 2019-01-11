#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::cout;
using std::endl;
 


class Animal {
  string d_name;
  int d_nLegs;
  
public:
  Animal(string name, int nLegs ) : d_name(name), d_nLegs(nLegs) {};

  const string toString() const {
    ostringstream os;
    os << d_name << " " << d_nLegs;
    return os.str();
  }
};


int save( const vector<Animal>& aVec, 
	  const string& fN = string("animals.txt")) {
  ofstream ofs(fN,std::fstream::app);
  if (!ofs) return 0;

  int cnt = 0;
  for ( const auto& ani:aVec ) {
    ofs << ani.toString() << endl;
    // if (cnt == 2 ) ofs.setstate( std::ios::failbit );
    if (ofs) ++cnt;
  }
  ofs.close();
  return cnt;
}





int main() {
  vector<Animal> aVec;
  aVec.emplace_back( "cheeta", 4 );
  aVec.emplace_back( "spider", 8 );
  aVec.emplace_back( "ants", 6 );
  aVec.emplace_back( "goose", 2 );

  cout << "Saved " << save( aVec ) << " " << "animals" << endl;

 
  return 0;
}
