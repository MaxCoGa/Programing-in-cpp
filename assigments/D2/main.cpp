
#include <iostream>
#include <cstdlib> 

#include "double_array.h"
/**
 * Devoir 2 CSI 2772[A] Robert Laganière
 * main.cpp
 * Écrire trois fonctions globales qui manipulent des tableaux en utilisant des pointeurs.
 * Votre programme doit remplir un tableau de doubles aléatoires,
 * les convertir et les écrire dans un tableau de type char pour finalement convertir ces char en string style C.
 * 
 * @author Maxime Côté-Gagné(8851539)
 * 
 */ 
using namespace std;
//1.
int main() {
    //2.
    double dArray[10]; //= {2.22, 2000.323, 222.4, 439.32, 98.44, 34.55, 126.434, 3.44, -234.22, -23.3 };//double array   use in 3
    char cArray[10];//character array use in 4
    char *sArray[10];//tableau de tableaux de char pour 10 chaînes de caractères style C. use in 5

    //pseudo-aleatoire from code given in assigment 2
    srand(42);
    for (auto &rVal : dArray) {//mets 10 valeurs aléatoire avec l'Adresse rVal
        rVal = -1000.0 + 2000.0 * static_cast<double> (rand()) / static_cast<double> (RAND_MAX);  
    }

    //3. print dArray
    printArray(dArray, 10);//print selected array with the correct choosen size, 10 in this case
  

    //4. make dArray(double) to cArray(char)
    double2char(dArray, cArray, 10);


    //something to print cArray
    cout << "\n" << "cArray: " << endl; 
    cout << "{";
    bool next=true; //check if next one need ","
    for (auto cVal : cArray) {// for each c(char)Val(value) in cArray
        if (!next) {
        cout << ", ";
        } else {
        next = false;
        }
        cout << static_cast<int>(cVal);
        }
    cout << "}" << endl;
  


    //5.
    //init the pointer use in sArray
    int newSize = 5;//work with 5
    char sData[10*newSize];//needed for storing all value of sArray* because it's a pointer
    char *psData = sData;
    for (auto &sVal : sArray){
        sVal = psData;
        psData+=newSize;
    }
    getCharacters(cArray, sArray, 10);//hint


    //6.
    //something to print sArray
    cout << "\n" << "sArray: " << endl; 
    cout << "{";
    next=true;
 
    for (auto &sVal : sArray){//for each string value in string array
        //int i(0);
        if (!next){
            cout << ", ";
        }else{
            next = false;
        }
        cout <<sVal;
        //i++;
        }
    cout << "}" << endl;



    return 0;
} 