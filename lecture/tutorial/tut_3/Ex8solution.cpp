#include <cstddef>
#include <iostream>

using namespace std ;



struct Node {
int x;
Node *next;
};

void initNode(struct Node *head, int n){
head->x = n;
head->next = NULL;

}

// (**Node)->(*Node)->head 
// le premier arg c'est un pointeur a un pointeur a un objet Node qu'on nomme head.
// on fait ca parce que les pointeurs sont passes par copie
// on ne peut donc pas modifier et retourner l'adresse d'un pointeur dans une fonction
// ... mais on peut modifier ce que pointe un pointeur!
void addNode(Node ** head, int n){
 Node *NewNode = new Node;
 NewNode-> x = n;
 NewNode -> next = *head;
 *head = NewNode;
} 

// qu'est-ce qui manque dans ce code?
// delete ?


int main()
{
struct Node *head = new Node;

initNode(head,5);
addNode(&head,10); // ici on passe l'adresse du pointeur head, qui est ensuite modifie dans addNode
addNode(&head,20);

while (head != NULL) {
    std::cout << head-> x << "\n";
    head = head -> next;
}
	// est-ce possible de reimprimer la liste?
	
	
    return 0;
}
