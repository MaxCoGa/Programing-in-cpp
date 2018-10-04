#include <iostream>
using namespace std ;
main()
{
   char * adr = "bonjour" ;
   char * adb ;
   for (adb=adr ; adb<adr+3 ; adb++) cout << *adb ;
   cout << "\n" ;
   adb = adr ;
   while (*adb) cout << *(adb++) ;
}
