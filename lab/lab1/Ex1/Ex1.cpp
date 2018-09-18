#include <iostream>

int main()
{
std::cout << "Enter a series of numbers" << std::endl;
int i;
int ctr = 0;

while (std::cin >> i)
   if (i < 0)
      ++ctr;

std::cout << ctr << " numbers were negative" << std::endl;

return 0;
}
