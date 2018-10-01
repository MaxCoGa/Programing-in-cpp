#include <iostream>
#include "double_array.h"
/**
 * Devoir 2 CSI 2772[A] Robert Laganière
 * double_array.cpp
 * Écrire trois fonctions globales qui manipulent des tableaux en utilisant des pointeurs.
 * Votre programme doit remplir un tableau de doubles aléatoires,
 * les convertir et les écrire dans un tableau de type char pour finalement convertir ces char en string style C.
 * 
 * @author Maxime Côté-Gagné(8851539)
 * 
 */ 
using namespace std;
//3.define printArray
void printArray(double *pDouble, int size) {
    cout << "dArray: " << endl;
    cout << "{";//first bracket


    bool next = true;//check if "," needed
    //loop for adding each value until the size is reach
    for (int i=0; i<size; ++i) {
        if (!next) {
        cout << ", ";
        } else {
        next = false;
        }

        cout << pDouble[i];
    }

    cout << "}" << endl;//last bracket

    return;
}

//4.return boolean and pick two pointer(source,destination), first one->double array, second one->char array, last paramter is use for the size(loop)
bool double2char(double *pDouble, char *pChar, int size) {
    for (int i=0; i<size; i++) {
        double tmpDouble;
        /**if(*pDouble > 127){
            tmpDouble = 127?: *pDouble;
        } else if(*pDouble < -128){
            tmpDouble = -128?:*pDouble;
        }*/
        bool condition1 = *pDouble > 127;//condition 1 :check if more than 127(the current value)
        tmpDouble = condition1 ? 127 :*pDouble; //? conditional with : actually work nice now it should work for all value but not for these <-128
        bool condition2 = tmpDouble < -128;//condition 2: check if tmpDouble is less than 128
        tmpDouble = condition2 ? -128 :tmpDouble;

        *pChar++ =  static_cast<char>(tmpDouble);//pChar[i++]
        pDouble++;//increment le pointeur
    }
    
}




//5.
bool getCharacters(char *pChar, char *pString[], int size) {//hint
    //char z = (char)(pString[2][2]);


    for ( int i=0; i<size; ++i ) {
        
        
        
        int pos = 0;// pString pointe vers un sArray(tableau de tableau) donc j'ai besoin d'une autre valeur pour trouvé la pos du char dans lequel on regarde
        int tmpChar = pChar[i];//tempory value of the current Char that the curret loop is going trhough
        int zeroASCII = 48; // on the ascii table zero start at 48
       
        //sArray[i][4]

        //find if -sign is present
        if (tmpChar < 0) {//work
            *(pString[i]) = '-';
            ++pos;
            tmpChar = -tmpChar;
        }

        //find the last value(far left) if the char is 3 chars long(- sign not include)
        if (static_cast<int>(tmpChar) > 99){ //work
            pString[i][pos++] = (tmpChar/100) + zeroASCII;
        } 
        

        //find the second value(right to left)
        if (static_cast<int>(tmpChar) > 9){
            //pString[i][pos++] = tmpChar/10 + 48;
            pString[i][pos++] = ((tmpChar%100)/10) + zeroASCII;
        }

        //change the first value(right one)
        pString[i][pos++] = (tmpChar%10) + zeroASCII;
        pString[i][pos] = 0;
        
  }
    //cout << "z: " << z <<endl;



    return true;


  
}
   