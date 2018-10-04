#include <iostream>
#include <string>
#include <sstream>

using namespace std;

union Combi {// union -> trois variables "occupent la meme zone de memoire"
int i;
short s;
char c;
};

int main() {
	
	Combi d; // exemple d union
	d.i = 0xFF1002;
	cout << sizeof(d) << endl;
	cout << sizeof(d.i) << endl;
	cout << sizeof(d.s) << endl;
	cout << d.s << endl;
	cout << static_cast<int>(d.c) << endl;
	
	
	// exemple de string style c
	char t[] = "Zero ce n'est 0 pas la \0 fin du string";
	char *c = t;
	int i = 0;
	
	while (*c) {
		cout << *c++;
		}
	cout << static_cast<int>(*c) <<endl; // Nul apres while
	
	char s1[] = "Allo"; // le \0 est ajoute automatiquement ici
	
	for (char c2 : s1) { // pour chaque char c2 dans s1
		cout << c2 + 2 ; // (char, int, +)-> int par promotion
	}
	cout << endl;
	
	for (char c2 : s1) { // pour chaque char c2 dans s1
		cout << static_cast<char>(c2 + 2) ; // imprime char(c2 + 2)
	}
	cout << endl;
	
	
	// exemple d operations niveau de bit
	signed int a = 0xFF, b= 0x0F0F; 
	a ^= b; // A <- (0000 0000 1111 1111) XOR (0000 1111 0000 11111)
	std::stringstream stream; // besoin de <sstream> pour convrertix hex
	stream << std::hex << a; // mets std::hex, a dans stream pour envoyer en forme hex
	std::string result( stream.str() ); // stream.str() pour convertir sstream en string
	cout << "a " << a << endl;
	cout << "result " << result <<endl;
	

	
	int A[][2] = {10,20,30,40}; // equivalent a A[2][2] -> le compilateur le deduit de la liste init
	
	int (*ptr)[2] = &A[0]; // pointeur a un tableau de int de taille 2, initialise a l'adresse du premier element de A (qui est aussi un pointeur de int de taille 2)
	
	int g = **(++ptr); // augmente ptr (ce qui avance le pointeur de un, a A[1]) et suis les pointeurs a la valeur du premier element du deuxieme tableau 
	std::cout << g << endl;
}
