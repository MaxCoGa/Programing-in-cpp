#include <iostream>

using std::cout;
using std::endl;

using std::ostream;


class Node {
  int d_element;
protected:
  Node* d_neighbour[4]{0,0,0,0};
  
public:
  Node( int element ) : d_element(element) {}
 
  Node( const Node& on ) : d_element(on.d_element) {
    for ( int i=0; i<4; ++i ) {
      if ( on.d_neighbour[i] ) d_neighbour[i] = new Node(on.d_neighbour[i]->d_element);
    }
  }

  ~Node() {
    for ( int i=0; i<4; ++i ) {
      if ( d_neighbour[i] ) delete d_neighbour[i];
    }
  }

 
  bool remove() {
    if ( d_neighbour[0] == 0 ) return false;
    delete d_neighbour[0];
    return true;
  }

  bool add( Node& on ) {
    if ( d_neighbour[3] != 0 ) return false;
    d_neighbour[3] = new Node(on);
    return true;
  }

  void rotate() {
    Node* tmp(d_neighbour[0]);
    cout << "rot" << endl;
    for ( int i=0; i<3; ++i ) {
      d_neighbour[i] = d_neighbour[i+1];
    }
    d_neighbour[3] = tmp;
    cout << "stop" << endl;
  }


  friend ostream& operator<<( ostream& os, const Node& node ) {
    os << node.d_element << " ";
    for ( auto nghbPtr:node.d_neighbour ) {
      if ( nghbPtr ) os << *nghbPtr;
    }
    return os;
  }
};



template <class T, const int N>
class NodeT {
  T d_element;
protected:
  NodeT<T,N>* d_neighbour[N];
  
public:
  NodeT( int element ) : d_element(element) {
    for ( auto& nghbPtr:d_neighbour ) nghbPtr = 0;
  }
 
  NodeT( const NodeT<T,N>& on ) : d_element(on.d_element) {
    for ( int i=0; i<N; ++i ) {
      if ( on.d_neighbour[i] ) 
         d_neighbour[i] = new NodeT<T,N>(on.d_neighbour[i]->d_element);
      else d_neighbour[i] = 0;
    }
  }

  ~NodeT() {
    for ( int i=0; i<N; ++i ) {
      if ( d_neighbour[i] ) delete d_neighbour[i];
    }
  }

 
  bool remove() {
    if ( d_neighbour[0] == 0 ) return false;
    delete d_neighbour[0];
    return true;
  }

  bool add( NodeT& on ) {
    if ( d_neighbour[N-1] != 0 ) return false;
    d_neighbour[N-1] = new NodeT<T,N>(on);
    return true;
  }

  void rotate() {
    NodeT* tmp(d_neighbour[0]);
    cout << "rot" << endl;
    for ( int i=0; i<N-1; ++i ) {
      d_neighbour[i] = d_neighbour[i+1];
    }
    d_neighbour[N-1] = tmp;
    cout << "stop" << endl;
  }

 
  friend ostream& operator<<( ostream& os, const NodeT<T,N>& node ) {
    os << node.d_element << " ";
    for ( auto nghbPtr:node.d_neighbour ) {
      if ( nghbPtr ) os << *nghbPtr;
    }
    return os;
  }
};






int main() {

  Node nArray[]{ 1,2,3,4,5 };
  // NodeT<int,4> nArray[]{ 1,2,3,4,5 };  


  for (int i=0;i<4;++i) {
    nArray[0].rotate();
    nArray[0].add(nArray[i+1]);
  }

  cout << nArray[0] << endl;

  return 0;
}
