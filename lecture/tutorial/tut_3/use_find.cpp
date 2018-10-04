#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
 

int main()
{
    int n1 = 3;
    int n2 = 5;
 
    std::vector<int> v{0, 1, 2, 3, 4};
 
    auto result1 = std::find(std::begin(v), std::end(v), n1);
    auto result2 = std::find(std::begin(v), std::end(v), n2);
 
    if (result1 != std::end(v)) {
        std::cout << "v contains: " << n1 << '\n';
    } else {
        std::cout << "v does not contain: " << n1 << '\n';
    }
 
    if (result2 != std::end(v)) {
        std::cout << "v contains: " << n2 << '\n';
    } else {
        std::cout << "v does not contain: " << n2 << '\n';
    }

	char a[] = {'a', 'b', 'c', 'd'};
	char c1 = 'a';
	char c2 = 'f';
	
	auto result3 = std::find(std::begin(a), std::end(a), c1);
	auto result4 = std::find(std::begin(a), std::end(a), c2);
	if (result3 != std::end(a)) {
        std::cout << "a contains: " << c1 << '\n';
    } else {
        std::cout << "a does not contain: " << c1 << '\n';
    }
    
    if (result4 != std::end(a)) {
        std::cout << "a contains: " << c2 << '\n';
    } else {
        std::cout << "a does not contain: " << c2 << '\n';
    }

}
