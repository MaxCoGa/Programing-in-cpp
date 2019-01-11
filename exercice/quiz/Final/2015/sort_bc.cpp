#include <algorithm>
#include <vector>
#include <iostream> 
#include <string>

using std::sort;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::ostream;


struct BuildingCode {
  string d_code;
  string d_name;
  int d_num;

  friend ostream& operator<<( ostream& os, const BuildingCode& bc ) {
    os << bc.d_code << ": " << bc.d_name << " " << bc.d_num;
    return os;
  }
};



int main() {
  vector<BuildingCode> bcVec{{"STE","SITE",800},
                             {"MNT","Montpetit",125},
	                     {"MRN","Marion",140},
	                     {"VNR","Vanier",11},
	                     {"LMX","Lamoureux",145},
	                     {"MCD","MacDonald",150}};


  sort( bcVec.begin(), bcVec.end(), [](const BuildingCode& a, const BuildingCode& b) { return a.d_num < b.d_num;} );
  for ( auto bc:bcVec ) cout << bc << endl;
  cout << endl;

  sort( bcVec.begin(), bcVec.end(), [](const BuildingCode& a, const BuildingCode& b) { return b.d_code < a.d_code;} );
  for ( auto bc:bcVec ) cout << bc << endl;

  return 0;
}
  
