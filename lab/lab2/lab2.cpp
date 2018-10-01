#include <string>
#include <iostream>
using namespace std;

/** You will find global functions in #include <cstring> which behave
 *  similiarly. The assignment did not explicitly disallow their use
 *  but implementing your own would have been to your benefit here.
 */
void copyCstring( char* strA, char* strB ){
  int i = 0;
  while(*(strA+i)){
    *strB = *(strA + i);
    strA++;
    strB++;
  }
  *strB=0;
  
}

/**
 * return 1 if strA > strB, 0 if strA = strB and 1 if strA = strB
 */
int compareCstring( char *strA, char *strB){
  while(true){
    if(*strA != 0){
      if(*strB == 0 || *strA > *strB){
        return 1;
      }
      if(*strA < *strB){
        return -1;
      } 
    } else {
      if(*strB != 0) {
        return -1;
      }
      return 0;
    }
    ++strA;
    ++strB;
  }
}


/**
 * Sorting a word array using old-style C-strings
 */
void sortWords( char words2Darray[][10], int length ) {
  // simple bubblesort
  for (int i = 0; i < length -1 ; i++)
    for (int j = i + 1; j < length; j++) {
      if (compareCstring(words2Darray[i], words2Darray[j]) > 0) {
        char temp[10];
        copyCstring(temp, words2Darray[i]);
        copyCstring(words2Darray[i], words2Darray[j]);
        copyCstring(words2Darray[j], temp);
      }
    }
}



int main() {
  char A[5][10]= { "java",
          "fancy",
          "yeah",
          "fantastic",
          "elastic" };

  char a[] = "allo";
  char b[10];
  copyCstring(a,b);

  cout<<"b: " <<b<<endl;

  sortWords(A, 5);

  for (int i=0; i<5; i++)
      std::cout << A[i] << std::endl;

  return 0;
}

