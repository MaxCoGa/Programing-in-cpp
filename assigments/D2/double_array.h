#ifndef DOUBLE_ARRAY_H_
#define DOUBLE_ARRAY_H_
/**
 * Devoir 2 CSI 2772[A] Robert Laganière
 * double_array.h
 * Écrire trois fonctions globales qui manipulent des tableaux en utilisant des pointeurs.
 * Votre programme doit remplir un tableau de doubles aléatoires,
 * les convertir et les écrire dans un tableau de type char pour finalement convertir ces char en string style C.
 * 
 * @author Maxime Côté-Gagné(8851539)
 * 
 */ 
//Double->Char->String
void printArray(double *pDdouble, int size);
bool double2char(double *pDdouble, char *pChar, int size);
bool getCharacters(char *pChar, char *pString[], int size);//hint

#endif