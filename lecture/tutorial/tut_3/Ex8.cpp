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

void addNode(struct Node * head, int n){
    struct Node *NewNode = new Node;
 NewNode-> x = n;
 NewNode -> next = head;
 head = NewNode;
}

main9()
{
struct Node *head = new Node;

initNode(head,5);
addNode(head,10);
addNode(head,20);

while (head != NULL) {
    std::cout << head-> x << "\n";
    head = head -> next;
}

    return 0;
}

//ca ne fonctionne pas, pourquoi? il faut transmettre &head...
//------------------------------------------
