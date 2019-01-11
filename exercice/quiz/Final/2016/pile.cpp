#include <iostream> 
#include <deque> 
#include <algorithm> 

using namespace std ; 

template <class T>
void print (T& container) {
	for ( auto& e : container ) cout << e << " ";
	cout << endl;
	return;
}

int main() {
  char mot[] = {"xyz"}; 
  deque<char> pl(mot, mot+3); print(pl); 
  pl.push_front('a'); print(pl); 
  pl[2] = '+'; 
  pl.push_front('b'); 
  pl.pop_back(); print(pl); 
  auto ip = find (pl.begin(), pl.end(), 'x'); 
  pl.erase(pl.begin(), ip); print(pl); 

  return 0;
} 
