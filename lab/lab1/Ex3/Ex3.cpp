#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int nbr;
    cout << "donnez un nombre positif :" << std::endl;
    cin >> nbr;

    while (nbr != 0) {
        if (nbr >0)
            cout << "sa racine carrée est :" << sqrt(nbr) << std::endl;
        else
            cout << "svp positif" << std::endl;

        cin >> nbr;
    }

    cout << "donnez un nombre positif : 0" << std::endl;
    return 0;
}
