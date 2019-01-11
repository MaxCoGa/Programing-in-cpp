#include <iostream> 
#include <list> 

using namespace std;

using LISTINT=list<int>; 

int main() { 
  LISTINT li; 
  li.push_front (2); 
  li.push_front (1); 
  li.push_back (3); 
  for( auto i=li.cbegin(); i!=li.cend(); ++i) 
    cout<<*i<<" "; 
  cout<<endl; 
  for(auto i=li.rbegin(); i!=li.rend(); ++i) 
    cout<<*i<<" "; 
  cout<<endl; 
	return 0;
}
