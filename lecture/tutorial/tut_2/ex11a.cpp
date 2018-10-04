#include <iostream>
using namespace std ;
main()
{
   char * adr = "bonjour" ;
   int i ;
   for (i=0 ; i<3 ; i++) cout << *(adr+i) ; // adr[i]
   cout << "\n" ;
   i = 0 ;
   while (*(adr+i)) cout << *(adr+i++) ; // adr[i++] 
}
