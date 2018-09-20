#include <iostream>
using namespace std ;
main()
{
   char * jour [7] = { "lundi", "mardi", "mercredi",   
               "jeudi", "vendredi", "samedi", "dimanche"} ;
   int i ;
   do {
       cout << "donnez un nombre entier entre 1 et 7 : " ;
       cin >> i ;
   }
   while ( i<=0 || i>7) ;
   
   cout << "le jour numéro " << i << 
                       " de la semaine est " << jour[i-1] ;
}
