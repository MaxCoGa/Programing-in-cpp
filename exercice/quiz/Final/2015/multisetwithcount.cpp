#include <iostream>
#include <string>
#include <vector>
#include <map>

template <typename T>
class MultiSetWithCount {
	// map containing one instance and its associated count
	std::map<T,int> d_store;
public:
	// returns how many times this object was inserted
	int getCount(const T& object) {
		auto it = d_store.find(object);
		if ( it == d_store.end()) // ___________________
			return 0;
		else
			return it->second; // ___________________
	}
	
	// Adds an object
	// If object is new then count starts at 1
	// If object already exists then simply increment count
	void add(const T& object) {
		d_store.insert(make_pair(object, 0)).first->second++;
	}

	// Remove an object. The object will be completely removed from the map
	// Returns the number of objects removed
	int remove(const T& object) {
		auto it= d_store.find(object); // _______________________
		int numberOfDeletedObjects= 0;
		if (it!= d_store.end()) {
			numberOfDeletedObjects = it->second; //____________________
			d_store.erase(it); //_______________________
		}
		return numberOfDeletedObjects;
	}
	
	// Returns a vector containing the objects
	// For each object the number of copies to create for the vector
	// corresponds to the count value
	std::vector<T> toVector() {
		std::vector<T> v;
		for (auto iterator= d_store.cbegin();
				 iterator != d_store.cend(); ++iterator) { //__________________
			int count= iterator->second; //____________________
			for (int i=0; i< count; i++) {
				v.push_back(iterator->first); //__________________
			}
		}
		return v;
	}
	
	// prints all values and counts
	void print() {
		for (auto iterator=d_store.cbegin();
				 iterator != d_store.cend(); ++iterator) { // ____________________
			std::cout << "(" << iterator->first
								<< "," << iterator->second << ")"; // ____________________
		}
		std::cout << std::endl;
	}
};

int main() {
	MultiSetWithCount<std::string> ms;
	ms.add(std::string("red"));
	ms.add(std::string("red"));
	ms.add(std::string("green"));
	ms.add(std::string("green"));
	ms.add(std::string("blue"));
	ms.add(std::string("green"));
	std::cout << "green count is " <<
		ms.getCount(std::string("green")) << std::endl;
	std::cout << ms.remove(std::string("red")) << std::endl;
	ms.print();
	std::vector<std::string> v= ms.toVector();
	std::cout << "vector size is " << v.size() << std::endl;
	return 0;
}

/* Console output:
	 green count is 3
	 2
	 (blue,1)(green,3)
	 vector size is 4
*/
